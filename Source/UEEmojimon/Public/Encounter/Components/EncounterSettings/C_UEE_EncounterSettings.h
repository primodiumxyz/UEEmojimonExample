// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Component/CF_Component.h"
#include "UObject/Object.h"
#include "Encounter/UI/W_UEE_Encounter.h"
#include "C_UEE_EncounterSettings.generated.h"

USTRUCT(BlueprintType)
struct UEEMOJIMON_API FC_UEE_EncounterSettings : public FCF_Component 
{
	GENERATED_BODY()
public:


	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSubclassOf<UW_UEE_Encounter> EncounterUIClass= nullptr;
	

	
	
	FC_UEE_EncounterSettings()
	{
		EncounterUIClass = nullptr;
	}

	FC_UEE_EncounterSettings(TSubclassOf<UW_UEE_Encounter> _EncounterUIClass)
	{
		EncounterUIClass = _EncounterUIClass;
	}
	
};