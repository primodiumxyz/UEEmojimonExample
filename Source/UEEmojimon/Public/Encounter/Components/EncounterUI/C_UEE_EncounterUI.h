// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Component/CF_Component.h"
#include "UObject/Object.h"
#include "Encounter/UI/W_UEE_Encounter.h"
#include "C_UEE_EncounterUI.generated.h"



USTRUCT(BlueprintType)
struct UEEMOJIMON_API FC_UEE_EncounterUI : public FCF_Component 
{
	GENERATED_BODY()
public:


	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	UW_UEE_Encounter* EncounterUI = nullptr;
	

	
	
	FC_UEE_EncounterUI()
	{
		EncounterUI = nullptr;
	}

	FC_UEE_EncounterUI(UW_UEE_Encounter* _EncounterUI)
	{
		EncounterUI = _EncounterUI;
	}
	
};