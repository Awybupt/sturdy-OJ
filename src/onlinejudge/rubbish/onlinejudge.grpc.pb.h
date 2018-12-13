// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: onlinejudge.proto
// Original file comments:
// first version of oj.proto
// mike@2018.12.06
// wxscs@qq.com
//
#ifndef GRPC_onlinejudge_2eproto__INCLUDED
#define GRPC_onlinejudge_2eproto__INCLUDED

#include "onlinejudge.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace onlinejudge {

// define massage type.
class OnlineJudge final {
 public:
  static constexpr char const* service_full_name() {
    return "onlinejudge.OnlineJudge";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    std::unique_ptr< ::grpc::ClientReaderInterface< ::onlinejudge::qName>> listQues(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::onlinejudge::qName>>(listQuesRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::onlinejudge::qName>> AsynclistQues(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::onlinejudge::qName>>(AsynclistQuesRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::onlinejudge::qName>> PrepareAsynclistQues(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::onlinejudge::qName>>(PrepareAsynclistQuesRaw(context, request, cq));
    }
    virtual ::grpc::Status detailQues(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::onlinejudge::qUestion* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::qUestion>> AsyncdetailQues(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::qUestion>>(AsyncdetailQuesRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::qUestion>> PrepareAsyncdetailQues(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::qUestion>>(PrepareAsyncdetailQuesRaw(context, request, cq));
    }
    virtual ::grpc::Status jUdge(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::onlinejudge::replyResult* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::replyResult>> AsyncjUdge(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::replyResult>>(AsyncjUdgeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::replyResult>> PrepareAsyncjUdge(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::replyResult>>(PrepareAsyncjUdgeRaw(context, request, cq));
    }
    virtual ::grpc::Status rEsult(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::onlinejudge::replyResult* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::replyResult>> AsyncrEsult(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::replyResult>>(AsyncrEsultRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::replyResult>> PrepareAsyncrEsult(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::replyResult>>(PrepareAsyncrEsultRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void detailQues(::grpc::ClientContext* context, const ::onlinejudge::qName* request, ::onlinejudge::qUestion* response, std::function<void(::grpc::Status)>) = 0;
      virtual void jUdge(::grpc::ClientContext* context, const ::onlinejudge::qSubmit* request, ::onlinejudge::replyResult* response, std::function<void(::grpc::Status)>) = 0;
      virtual void rEsult(::grpc::ClientContext* context, const ::onlinejudge::qName* request, ::onlinejudge::replyResult* response, std::function<void(::grpc::Status)>) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientReaderInterface< ::onlinejudge::qName>* listQuesRaw(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::onlinejudge::qName>* AsynclistQuesRaw(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::onlinejudge::qName>* PrepareAsynclistQuesRaw(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::qUestion>* AsyncdetailQuesRaw(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::qUestion>* PrepareAsyncdetailQuesRaw(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::replyResult>* AsyncjUdgeRaw(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::replyResult>* PrepareAsyncjUdgeRaw(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::replyResult>* AsyncrEsultRaw(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::onlinejudge::replyResult>* PrepareAsyncrEsultRaw(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    std::unique_ptr< ::grpc::ClientReader< ::onlinejudge::qName>> listQues(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::onlinejudge::qName>>(listQuesRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::onlinejudge::qName>> AsynclistQues(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::onlinejudge::qName>>(AsynclistQuesRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::onlinejudge::qName>> PrepareAsynclistQues(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::onlinejudge::qName>>(PrepareAsynclistQuesRaw(context, request, cq));
    }
    ::grpc::Status detailQues(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::onlinejudge::qUestion* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onlinejudge::qUestion>> AsyncdetailQues(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onlinejudge::qUestion>>(AsyncdetailQuesRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onlinejudge::qUestion>> PrepareAsyncdetailQues(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onlinejudge::qUestion>>(PrepareAsyncdetailQuesRaw(context, request, cq));
    }
    ::grpc::Status jUdge(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::onlinejudge::replyResult* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onlinejudge::replyResult>> AsyncjUdge(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onlinejudge::replyResult>>(AsyncjUdgeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onlinejudge::replyResult>> PrepareAsyncjUdge(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onlinejudge::replyResult>>(PrepareAsyncjUdgeRaw(context, request, cq));
    }
    ::grpc::Status rEsult(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::onlinejudge::replyResult* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onlinejudge::replyResult>> AsyncrEsult(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onlinejudge::replyResult>>(AsyncrEsultRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onlinejudge::replyResult>> PrepareAsyncrEsult(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onlinejudge::replyResult>>(PrepareAsyncrEsultRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void detailQues(::grpc::ClientContext* context, const ::onlinejudge::qName* request, ::onlinejudge::qUestion* response, std::function<void(::grpc::Status)>) override;
      void jUdge(::grpc::ClientContext* context, const ::onlinejudge::qSubmit* request, ::onlinejudge::replyResult* response, std::function<void(::grpc::Status)>) override;
      void rEsult(::grpc::ClientContext* context, const ::onlinejudge::qName* request, ::onlinejudge::replyResult* response, std::function<void(::grpc::Status)>) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientReader< ::onlinejudge::qName>* listQuesRaw(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request) override;
    ::grpc::ClientAsyncReader< ::onlinejudge::qName>* AsynclistQuesRaw(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::onlinejudge::qName>* PrepareAsynclistQuesRaw(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::onlinejudge::qUestion>* AsyncdetailQuesRaw(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::onlinejudge::qUestion>* PrepareAsyncdetailQuesRaw(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::onlinejudge::replyResult>* AsyncjUdgeRaw(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::onlinejudge::replyResult>* PrepareAsyncjUdgeRaw(::grpc::ClientContext* context, const ::onlinejudge::qSubmit& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::onlinejudge::replyResult>* AsyncrEsultRaw(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::onlinejudge::replyResult>* PrepareAsyncrEsultRaw(::grpc::ClientContext* context, const ::onlinejudge::qName& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_listQues_;
    const ::grpc::internal::RpcMethod rpcmethod_detailQues_;
    const ::grpc::internal::RpcMethod rpcmethod_jUdge_;
    const ::grpc::internal::RpcMethod rpcmethod_rEsult_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status listQues(::grpc::ServerContext* context, const ::onlinejudge::qSubmit* request, ::grpc::ServerWriter< ::onlinejudge::qName>* writer);
    virtual ::grpc::Status detailQues(::grpc::ServerContext* context, const ::onlinejudge::qName* request, ::onlinejudge::qUestion* response);
    virtual ::grpc::Status jUdge(::grpc::ServerContext* context, const ::onlinejudge::qSubmit* request, ::onlinejudge::replyResult* response);
    virtual ::grpc::Status rEsult(::grpc::ServerContext* context, const ::onlinejudge::qName* request, ::onlinejudge::replyResult* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_listQues : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_listQues() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_listQues() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status listQues(::grpc::ServerContext* context, const ::onlinejudge::qSubmit* request, ::grpc::ServerWriter< ::onlinejudge::qName>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestlistQues(::grpc::ServerContext* context, ::onlinejudge::qSubmit* request, ::grpc::ServerAsyncWriter< ::onlinejudge::qName>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(0, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_detailQues : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_detailQues() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_detailQues() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status detailQues(::grpc::ServerContext* context, const ::onlinejudge::qName* request, ::onlinejudge::qUestion* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestdetailQues(::grpc::ServerContext* context, ::onlinejudge::qName* request, ::grpc::ServerAsyncResponseWriter< ::onlinejudge::qUestion>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_jUdge : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_jUdge() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_jUdge() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status jUdge(::grpc::ServerContext* context, const ::onlinejudge::qSubmit* request, ::onlinejudge::replyResult* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestjUdge(::grpc::ServerContext* context, ::onlinejudge::qSubmit* request, ::grpc::ServerAsyncResponseWriter< ::onlinejudge::replyResult>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_rEsult : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_rEsult() {
      ::grpc::Service::MarkMethodAsync(3);
    }
    ~WithAsyncMethod_rEsult() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status rEsult(::grpc::ServerContext* context, const ::onlinejudge::qName* request, ::onlinejudge::replyResult* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestrEsult(::grpc::ServerContext* context, ::onlinejudge::qName* request, ::grpc::ServerAsyncResponseWriter< ::onlinejudge::replyResult>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(3, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_listQues<WithAsyncMethod_detailQues<WithAsyncMethod_jUdge<WithAsyncMethod_rEsult<Service > > > > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_listQues : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_listQues() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_listQues() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status listQues(::grpc::ServerContext* context, const ::onlinejudge::qSubmit* request, ::grpc::ServerWriter< ::onlinejudge::qName>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_detailQues : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_detailQues() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_detailQues() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status detailQues(::grpc::ServerContext* context, const ::onlinejudge::qName* request, ::onlinejudge::qUestion* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_jUdge : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_jUdge() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_jUdge() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status jUdge(::grpc::ServerContext* context, const ::onlinejudge::qSubmit* request, ::onlinejudge::replyResult* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_rEsult : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_rEsult() {
      ::grpc::Service::MarkMethodGeneric(3);
    }
    ~WithGenericMethod_rEsult() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status rEsult(::grpc::ServerContext* context, const ::onlinejudge::qName* request, ::onlinejudge::replyResult* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_listQues : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_listQues() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_listQues() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status listQues(::grpc::ServerContext* context, const ::onlinejudge::qSubmit* request, ::grpc::ServerWriter< ::onlinejudge::qName>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestlistQues(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncWriter< ::grpc::ByteBuffer>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(0, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_detailQues : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_detailQues() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_detailQues() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status detailQues(::grpc::ServerContext* context, const ::onlinejudge::qName* request, ::onlinejudge::qUestion* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestdetailQues(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_jUdge : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_jUdge() {
      ::grpc::Service::MarkMethodRaw(2);
    }
    ~WithRawMethod_jUdge() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status jUdge(::grpc::ServerContext* context, const ::onlinejudge::qSubmit* request, ::onlinejudge::replyResult* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestjUdge(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_rEsult : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_rEsult() {
      ::grpc::Service::MarkMethodRaw(3);
    }
    ~WithRawMethod_rEsult() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status rEsult(::grpc::ServerContext* context, const ::onlinejudge::qName* request, ::onlinejudge::replyResult* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestrEsult(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(3, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_detailQues : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_detailQues() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler< ::onlinejudge::qName, ::onlinejudge::qUestion>(std::bind(&WithStreamedUnaryMethod_detailQues<BaseClass>::StreameddetailQues, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_detailQues() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status detailQues(::grpc::ServerContext* context, const ::onlinejudge::qName* request, ::onlinejudge::qUestion* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreameddetailQues(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::onlinejudge::qName,::onlinejudge::qUestion>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_jUdge : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_jUdge() {
      ::grpc::Service::MarkMethodStreamed(2,
        new ::grpc::internal::StreamedUnaryHandler< ::onlinejudge::qSubmit, ::onlinejudge::replyResult>(std::bind(&WithStreamedUnaryMethod_jUdge<BaseClass>::StreamedjUdge, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_jUdge() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status jUdge(::grpc::ServerContext* context, const ::onlinejudge::qSubmit* request, ::onlinejudge::replyResult* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedjUdge(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::onlinejudge::qSubmit,::onlinejudge::replyResult>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_rEsult : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_rEsult() {
      ::grpc::Service::MarkMethodStreamed(3,
        new ::grpc::internal::StreamedUnaryHandler< ::onlinejudge::qName, ::onlinejudge::replyResult>(std::bind(&WithStreamedUnaryMethod_rEsult<BaseClass>::StreamedrEsult, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_rEsult() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status rEsult(::grpc::ServerContext* context, const ::onlinejudge::qName* request, ::onlinejudge::replyResult* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedrEsult(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::onlinejudge::qName,::onlinejudge::replyResult>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_detailQues<WithStreamedUnaryMethod_jUdge<WithStreamedUnaryMethod_rEsult<Service > > > StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_listQues : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithSplitStreamingMethod_listQues() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::SplitServerStreamingHandler< ::onlinejudge::qSubmit, ::onlinejudge::qName>(std::bind(&WithSplitStreamingMethod_listQues<BaseClass>::StreamedlistQues, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithSplitStreamingMethod_listQues() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status listQues(::grpc::ServerContext* context, const ::onlinejudge::qSubmit* request, ::grpc::ServerWriter< ::onlinejudge::qName>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedlistQues(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::onlinejudge::qSubmit,::onlinejudge::qName>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_listQues<Service > SplitStreamedService;
  typedef WithSplitStreamingMethod_listQues<WithStreamedUnaryMethod_detailQues<WithStreamedUnaryMethod_jUdge<WithStreamedUnaryMethod_rEsult<Service > > > > StreamedService;
};

}  // namespace onlinejudge


#endif  // GRPC_onlinejudge_2eproto__INCLUDED
