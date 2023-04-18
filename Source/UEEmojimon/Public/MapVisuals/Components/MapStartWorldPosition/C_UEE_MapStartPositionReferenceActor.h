// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Component/CF_Component.h"
#include "UObject/Object.h"
#include "C_UEE_MapStartPositionReferenceActor.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)
struct UEEMOJIMON_API FC_UEE_MapStartPositionReferenceActor : public FCF_Component
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	AActor* MapStartPositionReferenceActor = nullptr;

	FC_UEE_MapStartPositionReferenceActor()
	{
		MapStartPositionReferenceActor = nullptr;
	}

	FC_UEE_MapStartPositionReferenceActor(AActor* _MapStartPositionReferenceActor)
	{
		MapStartPositionReferenceActor = _MapStartPositionReferenceActor;
	}
	
};
