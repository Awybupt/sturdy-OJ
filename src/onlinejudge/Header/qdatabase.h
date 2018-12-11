#ifndef qdatabase_h
#define qdatabase_h

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>
#include <vector>

class database{
    
private:
    MYSQL *conn_ptr=NULL;    
public:
    database(const char* host,const char* user,const char* pw,const char* db)
    {
        conn_ptr = mysql_init(NULL);
        if (!conn_ptr){
            fprintf(stderr, "LOG---MYSQL init failed!\n");
            exit(0);
        }

        conn_ptr = mysql_real_connect(conn_ptr,host,user,pw,db,3306,NULL,0);
        if (conn_ptr) {
            std::cout<<"LOG---Database Connection has been built."<<std::endl;
        }
        else{
            std::cout<<"LOG---Database Connection Fail"<<std::endl;
            exit(0);
        }
    }
    ~database()
    {
        mysql_close(conn_ptr);
        std::cout<<"LOG---mysql has been closed!"<<std::endl;
    }
    std::vector<std::string> dbList()
    {
        std::vector<std::string> ans;
        int res = mysql_query(conn_ptr,"SELECT qName FROM question");
        if (res){
            std::cout<<"SELECT error: "<<mysql_error(conn_ptr)<<std::endl;
        }
        else{
            MYSQL_RES* res_ptr=mysql_store_result(conn_ptr);
            if (res_ptr)
            {
                unsigned long nn=(unsigned long) mysql_num_rows(res_ptr);
                std::cout<<"LOG---Retrieved "<<nn<<" rows:"<<std::endl;
                MYSQL_ROW sqlrow;
                while((sqlrow = mysql_fetch_row(res_ptr)))
                {
                    ans.push_back(*sqlrow);
                }
                mysql_free_result(res_ptr);
            }
        }
        return ans;
    }
    std::string dbDetail(std::string name){
        std::string ans;
        name="SELECT qDescribe FROM question WHERE qName=\""+name+"\"";
        const char* p = name.data();
        int res = mysql_query(conn_ptr,p);
        if (res){
            std::cout<<"SELECT error: "<<mysql_error(conn_ptr)<<std::endl;
        }
        else{
            MYSQL_RES* res_ptr=mysql_store_result(conn_ptr);
            if (res_ptr)
            {
                unsigned long anslen=(unsigned long) mysql_num_rows(res_ptr);
                std::cout<<"LOG---Retrieved "<<anslen<<" rows:"<<std::endl;
                if (anslen>0)
                {                    
                    MYSQL_ROW sqlrow;
                    while((sqlrow = mysql_fetch_row(res_ptr)))
                    {
                        ans = *sqlrow;
                    }
                    mysql_free_result(res_ptr);
                }
            }             
        }
        return ans;
    }
    int dbSubmit(std::string name){
        int ans=0;
        std::string filename=name+"/main.cpp";
        name="SELECT qHeader FROM question WHERE qName=\""+name+"\"";
        const char* p = name.data();
        const char* pfn=filename.data();
        
        int res = mysql_query(conn_ptr,p);
        if (res){
            std::cout<<"LOG---SELECT error: "<<mysql_error(conn_ptr)<<std::endl;
        }
        else{
            MYSQL_RES* res_ptr = mysql_store_result(conn_ptr);
            if (res_ptr)
            {
                unsigned long anslen = (unsigned long)mysql_num_rows(res_ptr);
                std::cout<<"LOG---Retrieved "<<anslen<<" rows:"<<std::endl;
                if (anslen>0)
                {       
                    MYSQL_ROW sqlrow;
                    while((sqlrow = mysql_fetch_row(res_ptr)))
                    {
                        std::ofstream mycout(pfn);
                        if (mycout.is_open())
                        {
                            ans = 1;
                            mycout<< *sqlrow;
                            mycout.close();
                        }
                        else
                        {
                            std::cout<<"LOG--- OUT file fail!"<<std::endl;
                        }                       
                    }
                    mysql_free_result(res_ptr);
                }
            }
        }
        return ans;
    }
        
    int dbResult(std::string name){
        int ans;
        name="SELECT qStatus FROM question WHERE qName=\""+name+"\"";
        const char* p = name.data();
        int res = mysql_query(conn_ptr,p);
        if (res){
            std::cout<<"SELECT error: "<<mysql_error(conn_ptr)<<std::endl;
        }
        else{
            MYSQL_RES* res_ptr=mysql_store_result(conn_ptr);
            if (res_ptr)
            {
                unsigned long nn=(unsigned long) mysql_num_rows(res_ptr);
                std::cout<<"LOG---Retrieved "<<nn<<" rows:"<<std::endl;
                MYSQL_ROW sqlrow;
                while((sqlrow = mysql_fetch_row(res_ptr)))
                {
                    ans=int(*sqlrow[0])-48;
                }
                mysql_free_result(res_ptr);
            }
        }
        return ans;
    }
    
    void dbChangestatus(std::string name){
        name="UPDATE question SET qStatus=1 WHERE qName=\""+name+"\"";
        const char* p = name.data();
        
        int res = mysql_query(conn_ptr,p);
        if (res){
            std::cout<<"Update error: "<<mysql_error(conn_ptr)<<std::endl;
        }
    }
};
#endif /* qdatabase_h */
