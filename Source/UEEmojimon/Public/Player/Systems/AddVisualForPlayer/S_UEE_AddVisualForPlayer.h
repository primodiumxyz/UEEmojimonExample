// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "S_UEE_AddVisualForPlayer.generated.h"

UCLASS()
class UEEMOJIMON_API US_UEE_AddVisualForPlayer : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:


	
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION()
	void OnMovableComponentSet(const FCF_ComponentSetMessageBase ECSStreamGrpcContextComponentSet);
};