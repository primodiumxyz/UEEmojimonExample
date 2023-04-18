// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "S_UEE_LoadPlayerVisualSettings.generated.h"



UCLASS()
class UEEMOJIMON_API US_UEE_LoadPlayerVisualSettings : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TSubclassOf<AActor> PlayerVisual = nullptr;
	TSubclassOf<AActor> NonLocalPlayerVisual = nullptr;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
};
