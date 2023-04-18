// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mud/Components/MapConfig/C_UEE_MapConfig.h"
#include "UObject/Object.h"
#include "DS_UEE_MapVisualSettings.generated.h"

/**
 * 
 */
UCLASS(Config=Game, defaultconfig, meta = (DisplayName="Map Visual Settings")) // Give it a better looking name in UI
class UEEMOJIMON_API UDS_UEE_MapVisualSettings : public UDeveloperSettings
{
	GENERATED_BODY()


public:

	UPROPERTY(Config,EditDefaultsOnly,BlueprintReadOnly)
	TMap<EMapConfig_Terrain,TSoftClassPtr<AActor>> TerrainVisuals;
	
};
