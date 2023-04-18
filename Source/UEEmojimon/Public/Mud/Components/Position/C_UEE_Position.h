// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Component/CF_Component.h"
#include "UObject/Object.h"
#include "C_UEE_Position.generated.h"


USTRUCT(BlueprintType)
struct UEEMOJIMON_API FC_UEE_Position : public FCF_Component
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 x = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 y = 0;

	FC_UEE_Position()
	{
		x = 0;
		y = 0;
	}

	FC_UEE_Position(int32 _x, int32 _y)
	{
		x = _x;
		y = _y;
	}
	
};
