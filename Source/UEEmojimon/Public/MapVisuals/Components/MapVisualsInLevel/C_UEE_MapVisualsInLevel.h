// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Component/CF_Component.h"
#include "UObject/Object.h"
#include "C_UEE_MapVisualsInLevel.generated.h"


USTRUCT(BlueprintType)
struct UEEMOJIMON_API FC_UEE_MapVisualsInLevel : public FCF_Component
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TArray<AActor*> MapVisualActors = TArray<AActor*>();

	
};
