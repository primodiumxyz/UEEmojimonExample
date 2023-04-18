// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Component/CF_Component.h"
#include "UObject/Object.h"
#include "C_UEE_PlayerVisualSettings.generated.h"


USTRUCT(BlueprintType)
struct UEEMOJIMON_API FC_UEE_PlayerVisualSettings : public FCF_Component 
{
	GENERATED_BODY()
public:


	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSubclassOf<AActor> LocalPlayerVisual = nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSubclassOf<AActor> NonLocalPlayerVisual = nullptr;

	
	
	FC_UEE_PlayerVisualSettings()
	{
		LocalPlayerVisual = nullptr;
		NonLocalPlayerVisual = nullptr;
	}

	FC_UEE_PlayerVisualSettings(TSubclassOf<AActor> _PlayerVisual, TSubclassOf<AActor> _NonLocalPlayerVisual)
	{
		LocalPlayerVisual = _PlayerVisual;
		NonLocalPlayerVisual = _NonLocalPlayerVisual;
	}
	
};