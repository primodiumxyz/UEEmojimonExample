//Generated by TurboLink CodeGenerator, do not edit!
#pragma once
#include "TurboLinkGrpcContext.h"
#include "SEcsstream/EcsStreamMessage.h"
#include "SEcsstream/EcsStreamMarshaling.h"
class GrpcContext_ECSStreamService_SubscribeToStreamLatest : public GrpcContext_Ping_Stream<ECSStreamService_SubscribeToStreamLatest_ReaderWriter, ::ecsstream::ECSStreamBlockBundleReply>
{
	friend class UECSStreamServiceClient;
	typedef GrpcContext_Ping_Stream<ECSStreamService_SubscribeToStreamLatest_ReaderWriter, ::ecsstream::ECSStreamBlockBundleReply> Super;

private:
	void Call(const FGrpcEcsstreamECSStreamBlockBundleRequest& Request);
	virtual void OnRpcEvent(bool Ok, const void* EventTag) override;

public:
	GrpcContext_ECSStreamService_SubscribeToStreamLatest(FGrpcContextHandle _Handle, UGrpcService* _Service, UGrpcClient* _Client);
};
