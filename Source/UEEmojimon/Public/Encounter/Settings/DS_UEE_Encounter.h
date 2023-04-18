// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Encounter/UI/W_UEE_Encounter.h"
#include "UObject/Object.h"
#include "DS_UEE_Encounter.generated.h"



UCLASS(Config=Game, defaultconfig, meta = (DisplayName="Encounter Settings")) // Give it a better looking name in UI
class UEEMOJIMON_API UDS_UEE_Encounter : public UDeveloperSettings
{
	GENERATED_BODY()


public:

	UPROPERTY(Config,EditDefaultsOnly,BlueprintReadOnly)
	TSoftClassPtr<UW_UEE_Encounter> EncounterUI;
	
	
};