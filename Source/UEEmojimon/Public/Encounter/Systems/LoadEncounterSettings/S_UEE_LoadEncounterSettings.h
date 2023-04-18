// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Encounter/UI/W_UEE_Encounter.h"
#include "S_UEE_LoadEncounterSettings.generated.h"


UCLASS()
class UEEMOJIMON_API US_UEE_LoadEncounterSettings : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TSubclassOf<UW_UEE_Encounter> EncounterUIClass;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
};
