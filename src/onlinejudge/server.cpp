#include "Header/qdatabase.h"
#include "Header/judge.h"


int main(int argc, char* argv[])
{
    if(argc == 2)
    {
        std::string sten=argv[1];
        if (sten == "list")
            judgeList();
        else
            useage();
    }
    else if (argc == 3)
    {
        std::string sten=argv[1];
        if (sten=="detail")
            judgeDetail(argv[2]);
        else if (sten=="result")
            judgeResult(argv[2]);
        else
            useage();
    }
    else if (argc == 4)
    {
        std::string sten=argv[1];
        if ( sten =="submit")
            judgeSubmit(argv[2], argv[3]);
        else
            useage();
    }
    else
        useage();
    std::cout<<"LOG--- Main Function"<<std::endl;
    return 0;
}
