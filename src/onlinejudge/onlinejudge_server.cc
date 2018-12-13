// first version of ojserver.cc
// mike@2018.12.12
// wxscs@qq.com

#include "Header/qdatabase.h"
#include "Header/judge.h"
#include <memory>

#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/security/server_credentials.h>

#include "onlinejudge.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;

using onlinejudge::qName;
using onlinejudge::qUestion;
using onlinejudge::qSubmit;
using onlinejudge::replyResult;
using onlinejudge::OnlineJudge;

class OnlineJudgeImpl final : public OnlineJudge::Service {

    public:
    Status listQues(ServerContext* context, const qSubmit* qsubmit,ServerWriter<qName>* writer) override {
        std::string qsignal = qsubmit->nickn();
        if(qsignal == "list")
        {
            std::vector<std::string> qnamelist;
            judgeList(qnamelist);
            unsigned int llen=qnamelist.size();
            for(unsigned int i=0;i<llen;i++)
            {
                qName temq;
                temq.set_keyname(qnamelist[i]); 
                writer->Write(temq);
            }
        }
        return Status::OK;
    }
    //return qName's detail.
    Status detailQues(ServerContext* context, const qName* qn,
                    qUestion* rqn) override {
        std::string Questioname=qn->keyname();
        rqn->set_nickn(Questioname);
        
        Questioname=judgeDetail(Questioname);
        rqn->set_message(Questioname);
        return Status::OK;
    }
    
    Status jUdge(ServerContext* context, const qSubmit* qsm,
                    replyResult* rR) override {
        std::string rn = qsm->nickn();
        std::string Tcode = qsm->qsubmitcode();
        rn = judgeSubmit(rn,Tcode);
        rR->set_message(rn);
        return Status::OK;
    }
    Status rEsult(ServerContext* context, const qName* qn,
                    replyResult* rR) override {
        std::string rn=qn->keyname();
        rn=judgeResult(rn);
        rR->set_message(rn);
        return Status::OK;
    }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  OnlineJudgeImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
    
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();
  return 0;
}
