//Generated by TurboLink CodeGenerator, do not edit!
#include "GreeterContext.h"
#include "SGreeter/GreeterClient.h"
#include "GreeterService_Private.h"
#include "GreeterMarshaling.h"
#include "TurboLinkGrpcManager.h"

GrpcContext_GreeterService_Hello::GrpcContext_GreeterService_Hello(FGrpcContextHandle _Handle, UGrpcService* _Service, UGrpcClient* _Client)
	: Super(_Handle, _Service, _Client)
{
}

void GrpcContext_GreeterService_Hello::Call(const FGrpcGreeterHelloRequest& Request)
{
	check(GetState() == EGrpcContextState::Ready);
	UpdateState(EGrpcContextState::Initialing);

	::Greeter::HelloRequest rpcRequest;
	TURBOLINK_TO_GRPC(&Request, &rpcRequest);

	UGreeterService* service = (UGreeterService*)Service;
	RpcReaderWriter = service->d->Stub->AsyncHello(RpcContext.get(), rpcRequest, service->TurboLinkManager->d->CompletionQueue.get());
	RpcReaderWriter->ReadInitialMetadata(InitialTag);
}

void GrpcContext_GreeterService_Hello::OnRpcEvent(bool Ok, const void* EventTag)
{
	Super::OnRpcEventInternal(Ok, EventTag, [this](const FGrpcResult& _Result, ::Greeter::HelloResponse* _RpcResponse) {
		UGreeterServiceClient* client = (UGreeterServiceClient*)(this->Client);
		if (!(client->OnHelloResponse.IsBound())) return;

		FGrpcGreeterHelloResponse response;
		if (_RpcResponse) {
			GRPC_TO_TURBOLINK(_RpcResponse, &response);
		}
		client->OnHelloResponse.Broadcast(Handle, _Result, response);
	});
}

GrpcContext_TimeService_Ticktok::GrpcContext_TimeService_Ticktok(FGrpcContextHandle _Handle, UGrpcService* _Service, UGrpcClient* _Client)
	: Super(_Handle, _Service, _Client)
{
}

void GrpcContext_TimeService_Ticktok::Call(const FGrpcGreeterTicktokRequest& Request)
{
	check(GetState() == EGrpcContextState::Ready);
	UpdateState(EGrpcContextState::Initialing);

	::Greeter::TicktokRequest rpcRequest;
	TURBOLINK_TO_GRPC(&Request, &rpcRequest);

	UTimeService* service = (UTimeService*)Service;
	RpcReaderWriter = service->d->Stub->AsyncTicktok(RpcContext.get(), rpcRequest, service->TurboLinkManager->d->CompletionQueue.get(), InitialTag);
}

void GrpcContext_TimeService_Ticktok::OnRpcEvent(bool Ok, const void* EventTag)
{
	Super::OnRpcEventInternal(Ok, EventTag, [this](const FGrpcResult& _Result, ::Greeter::NowResponse* _RpcResponse) {
		UTimeServiceClient* client = (UTimeServiceClient*)(this->Client);
		if (!(client->OnTicktokResponse.IsBound())) return;

		FGrpcGreeterNowResponse response;
		if (_RpcResponse) {
			GRPC_TO_TURBOLINK(_RpcResponse, &response);
		}
		client->OnTicktokResponse.Broadcast(Handle, _Result, response);
	});
}

GrpcContext_TimeService_Watch::GrpcContext_TimeService_Watch(FGrpcContextHandle _Handle, UGrpcService* _Service, UGrpcClient* _Client)
	: Super(_Handle, _Service, _Client)
{
}

void GrpcContext_TimeService_Watch::Init()
{
	check(GetState() == EGrpcContextState::Ready);
	UpdateState(EGrpcContextState::Initialing);

	UTimeService* service = (UTimeService*)Service;
	RpcReaderWriter = service->d->Stub->AsyncWatch(RpcContext.get(), service->TurboLinkManager->d->CompletionQueue.get(), InitialTag);
}

void GrpcContext_TimeService_Watch::Call(const FGrpcGreeterWatchRequest& Request)
{
	::Greeter::WatchRequest rpcRequest;
	TURBOLINK_TO_GRPC(&Request, &rpcRequest);

	if (CanSend) {
		RpcReaderWriter->Write(rpcRequest, WriteTag);
		CanSend = false;
	}
	else {
		SendQueue.push_back(rpcRequest);
	}
}

void GrpcContext_TimeService_Watch::OnRpcEvent(bool Ok, const void* EventTag)
{
	Super::OnRpcEventInternal(Ok, EventTag, [this](const FGrpcResult& _Result, ::Greeter::NowResponse* _RpcResponse) {
		UTimeServiceClient* client = (UTimeServiceClient*)(this->Client);
		if (!(client->OnWatchResponse.IsBound())) return;

		FGrpcGreeterNowResponse response;
		if (_RpcResponse) {
			GRPC_TO_TURBOLINK(_RpcResponse, &response);
		}
		client->OnWatchResponse.Broadcast(Handle, _Result, response);
	});
}