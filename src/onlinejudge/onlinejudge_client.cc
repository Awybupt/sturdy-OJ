// first version of oj.proto
// mike@2018.12.06
// wxscs@qq.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "onlinejudge.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;

using onlinejudge::qName;
using onlinejudge::qUestion;
using onlinejudge::qSubmit;
using onlinejudge::replyResult;
using onlinejudge::OnlineJudge;



qSubmit MakeqSubmit(const std::string& n, const std::string& s) {
  qSubmit p;
  p.set_nickn(n);
  p.set_qsubmitcode(s);
  return p;
}

class onlinejudgeClient {
    
 private:
    std::unique_ptr<OnlineJudge::Stub> stub_;
 public:
    onlinejudgeClient(std::shared_ptr<Channel> channel):stub_(OnlineJudge::NewStub(channel)) {}
    
    //list function,usage:[main] list 
    void List() {
        qSubmit qs;
        qName qn;
        ClientContext context;
        //define
        qs=MakeqSubmit("list","");
        std::unique_ptr<ClientReader<qName> > reader(
        stub_->listQues(&context, qs));
        //get value
        while (reader->Read(&qn)) {
            std::cout << qn.keyname() << std::endl;
        }
        
        Status status = reader->Finish();
        if (status.ok()) {
            std::cout << "ListFeatures rpc succeeded." << std::endl;
        } else {
            std::cout << "ListFeatures rpc failed." << std::endl;
        }
        
    }
    
    void Detail(std::string quname) {
        qName qn;
        qUestion qu;
        
        qn.set_keyname(quname);
        
        ClientContext context;
        Status status = stub_->detailQues(&context, qn, &qu);
        if (status.ok()) {
            std::cout<< qu.nickn()<<std::endl;
            std::cout<< qu.message()<<std::endl;
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
        }
    }
    
    void Submit(std::string quname,std::string fcd) {
        replyResult rR;
        qSubmit qs;
        qs.set_nickn(quname);
        
        
        qs.set_qsubmitcode(fcd);
        
        ClientContext context;
        Status status = stub_->jUdge(&context,qs, &rR);
        if (status.ok()) {
            std::cout<< rR.message()<<std::endl;
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
        }
    }
    
    void Result(std::string quname) {
        qName qn;
        replyResult rR;
        qn.set_keyname(quname);
        ClientContext context;
        Status status = stub_->rEsult(&context, qn, &rR);
        if (status.ok()) {
            std::cout<< rR.message()<<std::endl;
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
        }
    }
};

void useage()
{
    std::cout<<"Usage:  \nlist 列出题目列表\ndetail XXX 列出题目详情\nsubmit XXX code.c/cpp提交代码 & 你给他后台编译 & 判题\nresult XXX 查询判题结果"<<std::endl;
}


int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint (in this case,
  // localhost at port 50051). We indicate that the channel isn't authenticated
  // (use of InsecureChannelCredentials()).
  if(argc == 2)
    {
        std::string sten=argv[1];
        if (sten == "list")
        {
            onlinejudgeClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
            client.List();
        }
        else
            useage();
    }
    else if (argc == 3)
    {
        std::string sten=argv[1];
        if (sten=="detail")
        {
            onlinejudgeClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
            std::string name=argv[2];
            client.Detail(name);
        }
        else if (sten=="result")
        {
            onlinejudgeClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
            std::string name=argv[2];
            client.Result(name);
        }
        else
            useage();
    }
    else if (argc == 4)
    {
        std::string sten=argv[1];
        if ( sten =="submit")
        {
            onlinejudgeClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
            std::string name=argv[2];
            
            std::ifstream infile; 
            infile.open(argv[3]); 
            if (infile.is_open())
            {
                std::stringstream buffer;
                buffer << infile.rdbuf();
                std::string tempcode = buffer.str();
                infile.close();
                client.Submit(name,tempcode);
            }
            else
            {
                std::cout<<"ERROR FILE!"<<std::endl;
            }
        }
        else
            useage();
    }
    else
        useage();
    std::cout<<"LOG--- Main Function"<<std::endl;
    return 0;  
}
