// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BaseComponents/UInt32/C_UEM_UInt32.h"
#include "UObject/Object.h"
#include "C_UEE_MonsterType.generated.h"

UENUM(BlueprintType)
enum class EMonsterType : uint8 {
	None = 0 UMETA(DisplayName = "None"),
	Eagle = 1  UMETA(DisplayName = "Eagle"),
	Rat = 2     UMETA(DisplayName = "Rat"),
	Caterpillar = 2     UMETA(DisplayName = "Caterpillar"),
};


USTRUCT(BlueprintType)
struct UEEMOJIMON_API FC_UEE_MonsterType : public FC_UEM_UInt32
{
	GENERATED_BODY()
};
