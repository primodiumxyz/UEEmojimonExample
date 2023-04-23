// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Contract/Systems/MS_UEM_Base.h"
#include "UObject/Object.h"
#include "MS_UEE_Move.generated.h"



UCLASS()
class UEEMOJIMON_API UMS_UEE_Move : public UMS_UEM_Base
{
	GENERATED_BODY()

public:

	virtual FString GetSystemId() override;

	
	
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	
	UFUNCTION(BlueprintCallable)
	void OnMoveExecute(FM_UEE_Move_Execute Move_Execute);
};
