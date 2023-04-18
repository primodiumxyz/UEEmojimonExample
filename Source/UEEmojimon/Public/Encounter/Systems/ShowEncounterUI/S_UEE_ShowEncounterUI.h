// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Encounter/UI/W_UEE_Encounter.h"
#include "S_UEE_ShowEncounterUI.generated.h"

/**
 * 
 */
UCLASS()
class UEEMOJIMON_API US_UEE_ShowEncounterUI : public UGameInstanceSubsystem
{
	GENERATED_BODY()


public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;



	UFUNCTION()
	void OnEncounterComponentAdded(const FCF_ComponentSetMessageBase EncounterComponentSet);
	
};
