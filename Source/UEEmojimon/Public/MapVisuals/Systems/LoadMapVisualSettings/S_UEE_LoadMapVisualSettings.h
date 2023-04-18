// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mud/Components/MapConfig/C_UEE_MapConfig.h"
#include "S_UEE_LoadMapVisualSettings.generated.h"


UCLASS()
class UEEMOJIMON_API US_UEE_LoadMapVisualSettings : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TMap<EMapConfig_Terrain,TSubclassOf<AActor>> TerrainVisuals = TMap<EMapConfig_Terrain,TSubclassOf<AActor>>();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
};
