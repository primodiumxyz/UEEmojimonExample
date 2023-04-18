// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Component/CF_Component.h"
#include "Mud/Components/MapConfig/C_UEE_MapConfig.h"
#include "UObject/Object.h"
#include "C_UEE_MapVisualSettings.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct UEEMOJIMON_API FC_UEE_MapVisualSettings : public FCF_Component 
{
	GENERATED_BODY()
public:


	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TMap<EMapConfig_Terrain,TSubclassOf<AActor>> TerrainVisuals = TMap<EMapConfig_Terrain,TSubclassOf<AActor>>();
	
	
	FC_UEE_MapVisualSettings()
	{
		TerrainVisuals = TMap<EMapConfig_Terrain,TSubclassOf<AActor>>();
	}

	FC_UEE_MapVisualSettings(TMap<EMapConfig_Terrain,TSubclassOf<AActor>> _TerrainVisuals)
	{
		TerrainVisuals = TMap<EMapConfig_Terrain,TSubclassOf<AActor>>(_TerrainVisuals);
	}
	
};