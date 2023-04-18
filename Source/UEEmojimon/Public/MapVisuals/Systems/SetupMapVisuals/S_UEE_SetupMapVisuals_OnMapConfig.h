// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Mud/Components/MapConfig/C_UEE_MapConfig.h"
#include "S_UEE_SetupMapVisuals_OnMapConfig.generated.h"


UCLASS()
class UEEMOJIMON_API US_UEE_SetupMapVisuals_OnMapConfig : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:

	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION()
	void OnMapConfigComponentSet(const FCF_ComponentSetMessageBase ECSStreamGrpcContextComponentSet);
};