#ifndef judge_h
#define judge_h

#include <sstream>

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

void judgeSubmit(char *qName, char *filename)
{
    database *temp=new database(Dhost,Ddb,Dpw,Dtb);
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

            std::ofstream mycout("test/Solution.h");
            if (mycout.is_open())
            {
                mycout<<tempstring;
                mycout.close();
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
    delete temp;
}

#endif /* judge_h */