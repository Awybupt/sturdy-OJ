#ifndef judge_h
#define judge_h

#include <stdlib.h>
#include <sstream>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXLINE 64
#define Dhost "localhost"
#define Ddb "ojsql"
#define Dpw "654321"
#define Dtb "ojbase"


void useage()
{
    std::cout<<"Usage:  \nlist 列出题目列表\ndetail XXX 列出题目详情\nsubmit XXX code.c/cpp提交代码 & 你给他后台编译 & 判题\nresult XXX 查询判题结果"<<std::endl;
}

void judgeList()
{
    database *temp=new database(Dhost,Ddb,Dpw,Dtb);
    std::vector<std::string> qlist=temp->dbList();
    unsigned int llen=qlist.size();
    for(int i=0;i<llen;i++)
        std::cout<<qlist[i]<<std::endl;
    delete temp;
}

void judgeDetail(char *qName)
{
    database *temp=new database(Dhost,Ddb,Dpw,Dtb);
    std::string detaii=temp->dbDetail(qName);
    std::cout<<detaii<<std::endl;
    delete temp;
}

void judgeResult(char *qName)
{
    database *temp=new database(Dhost,Ddb,Dpw,Dtb);
    int he=temp->dbResult(qName);
    if (he == 0)//have more choice!
        std::cout<<"fail!"<<std::endl;
    else
        std::cout<<"success!"<<std::endl;
    delete temp;
}

int Jexec(std::string cmd, std::vector<std::string> &resvec) {
    resvec.clear();
    const char * realcmd=cmd.data();
    FILE *pp = popen(realcmd, "r"); //建立管道
    if (!pp) {
        return -1;
    }
    char tmp[128]; //设置一个合适的长度，以存储每一行输出
    while (fgets(tmp, sizeof(tmp), pp) != NULL) {
        if (tmp[strlen(tmp) - 1] == '\n') {
            tmp[strlen(tmp) - 1] = '\0'; //去除换行符
        }
        resvec.push_back(tmp);
    }
    pclose(pp); //关闭管道
    return resvec.size();
}

int Jexec(std::string cmd) {
    const char * realcmd=cmd.data();
    FILE *pp = popen(realcmd, "r"); //建立管道
    if (!pp)
        return 0;
    pclose(pp); //关闭管道
    return 1;
}

void judgeSubmit(char *qName, char *filename)
{
    database *temp=new database(Dhost,Ddb,Dpw,Dtb);
    std::string fakename=qName;
    if(Jexec("mkdir "+fakename))
    {
        int submitstatus=temp->dbSubmit(qName);
        if (submitstatus==1)
        {
            std::ifstream infile; 
            infile.open(filename); 
            if (infile.is_open())
            {
                std::stringstream buffer;
                buffer << infile.rdbuf();
                std::string tempstring = buffer.str();
                infile.close();
                
                std::string oufilname=fakename+"/Solution.h";
                const char* result = NULL;
                result=oufilname.c_str();
                std::ofstream mycout(result);
                if (mycout.is_open())
                {
                    mycout<<tempstring;
                    mycout.close();

                    //There are two file located in ./test\.
                    Jexec("timeout 0.5 g++ -Wfatal-errors -o "+fakename+"/main "+fakename+"/main.cpp");
                    result=(fakename+"/main").c_str();   
                    if (!access(result,F_OK))
                    {
                        std::vector<std::string> returnfile;
                        if (Jexec("timeout 0.5 ./"+fakename+"/main",returnfile))
                        {
                            if (returnfile[0][0]=='1')
                            {
                                temp->dbChangestatus(qName);
                                std::cout<<"LOG--- Congratulation!"<<std::endl;
                            }
                            else
                            {
                                std::cout<<"LOG--- fail!"<<std::endl;
                            }
                        }
                        else
                            std::cout<<"LOG--- Time out!"<<std::endl;
                        
                    }
                    else
                        std::cout<<"LOG--- compile code fail!"<<std::endl;
                    
                }
                else
                {
                    std::cout<<"LOG--- OUT solution code fail!"<<std::endl;
                }
            }
            else
            {
                std::cout<<"LOG--- IN solution code fail!"<<std::endl;
            } 
        }
        else
            std::cout<<"LOG--- Read database fail or without this file!"<<std::endl;
        Jexec("rm -rf "+fakename);
    }
    else
        std::cout<<"LOG--- MKDIR fail!"<<std::endl;
    delete temp;
}

#endif /* judge_h */