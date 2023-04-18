// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DS_UEE_PlayerVisual.generated.h"

/**
 * 
 */


UCLASS(Config=Game, defaultconfig, meta = (DisplayName="Player Visual Settings")) // Give it a better looking name in UI
class UEEMOJIMON_API UDS_UEE_PlayerVisual : public UDeveloperSettings
{
	GENERATED_BODY()


public:

	UPROPERTY(Config,EditDefaultsOnly,BlueprintReadOnly)
	TSoftClassPtr<AActor> PlayerVisual;

	UPROPERTY(Config,EditDefaultsOnly,BlueprintReadOnly)
	TSoftClassPtr<AActor> NonLocalPlayerVisual;
	
};
