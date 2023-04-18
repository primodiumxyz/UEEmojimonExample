//Generated by TurboLink CodeGenerator, do not edit!
#pragma once
#include "TurboLinkGrpcClient.h"
#include "SEcsstream/EcsStreamMessage.h"
#include "EcsStreamClient.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnECSStreamServiceSubscribeToStreamLatestResponse, FGrpcContextHandle, Handle, const FGrpcResult&, Result, const FGrpcEcsstreamECSStreamBlockBundleReply&, Response);

UCLASS(ClassGroup = TurboLink, BlueprintType)
class TURBOLINKGRPC_API UECSStreamServiceClient : public UGrpcClient
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnECSStreamServiceSubscribeToStreamLatestResponse OnSubscribeToStreamLatestResponse;

public:
	UFUNCTION(BlueprintCallable)
	FGrpcContextHandle InitSubscribeToStreamLatest();

	UFUNCTION(BlueprintCallable)
	void SubscribeToStreamLatest(FGrpcContextHandle Handle, const FGrpcEcsstreamECSStreamBlockBundleRequest& Request);

public:
	virtual void Shutdown() override;

	UFUNCTION(BlueprintCallable)
	void TryCancel(FGrpcContextHandle Handle);
};
