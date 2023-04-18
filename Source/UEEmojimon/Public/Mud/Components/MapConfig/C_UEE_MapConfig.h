// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Component/CF_Component.h"
#include "UObject/Object.h"
#include "C_UEE_MapConfig.generated.h"

UENUM(BlueprintType)
enum class EMapConfig_Terrain : uint8 {
	None = 0 UMETA(DisplayName = "None"),
	TallGrass = 1  UMETA(DisplayName = "TallGrass"),
	Boulder = 2     UMETA(DisplayName = "Boulder"),
};


USTRUCT(BlueprintType)
struct UEEMOJIMON_API FC_UEE_MapConfig : public FCF_Component
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	int32 Width = 0;

	UPROPERTY(BlueprintReadOnly)
	int32 Height = 0;

	UPROPERTY(BlueprintReadOnly)
	TArray<EMapConfig_Terrain> Terrains = TArray<EMapConfig_Terrain>();

	FC_UEE_MapConfig()
	{
		Width = 0;
		Height = 0;
		Terrains = TArray<EMapConfig_Terrain>();
	}

	FC_UEE_MapConfig(int32 _Width, int32 _Height, TArray<EMapConfig_Terrain> _Terrains)
	{
		Width = _Width;
		Height = _Height;
		Terrains = TArray<EMapConfig_Terrain>(_Terrains);
	}
	
};