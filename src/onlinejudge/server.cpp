#include "Header/qdatabase.h"
#include <sstream>
void useage()
{
    std::cout<<"Usage:  \nlist 列出题目列表\ndetail XXX 列出题目详情\nsubmit XXX 提交代码 & 你给他后台编译 & 判题\nresult XXX 查询判题结果"<<std::endl;
}

int main(int argc, char* argv[])
{
    if(argc == 2)
    {
        std::cout<<argv[1]<<std::endl;
        std::string sten=argv[1];
        if (sten == "list")
        {
            database *temp=new database("localhost","ojsql","654321","ojbase");
            std::vector<std::string> qlist=temp->dbList();
            unsigned int llen=qlist.size();
            for(int i=0;i<llen;i++)
                std::cout<<qlist[i]<<std::endl;
            delete temp;
        }
        else
            useage();
    }
    else if (argc == 3)
    {
        std::string sten=argv[1];
        if (sten=="detail")
        {
            database *temp=new database("localhost","ojsql","654321","ojbase");
            std::string detaii=temp->dbDetail(argv[2]);
            std::cout<<detaii<<std::endl;
            delete temp;
        }
        else if (sten=="result")
        {
            database *temp=new database("localhost","ojsql","654321","ojbase");
            int he=temp->dbResult(argv[2]);
            if (he == 0)
                std::cout<<"fail!"<<std::endl;
            else
                std::cout<<"success"<<std::endl;
            delete temp;
        }
        else
            useage();
    }
    else if (argc == 4)
    {
        std::string sten=argv[1];
        if ( sten =="submit")
        {
            database *temp=new database("localhost","ojsql","654321","ojbase");
            int sss=temp->dbSubmit(argv[2]);
            if (sss==1)
            {
                std::ifstream infile; 
                infile.open(argv[3]); 
                std::stringstream buffer;
                buffer << infile.rdbuf();
                std::string temps = buffer.str();
                infile.close();
                std::ofstream mycout("test/Solution.h");
                if (mycout.is_open())
                {
                    mycout<<temps;
                    mycout.close();
                }
                else
                {
                    std::cout<<"LOG--- OUT file fail!"<<std::endl;
                }
            }
            else
                std::cout<<"LOG--- Read database fail!"<<std::endl;
            delete temp;
        }
        else
            useage();
    }
    else
        useage();
    std::cout<<"Main Function"<<std::endl;
    return 0;
}
