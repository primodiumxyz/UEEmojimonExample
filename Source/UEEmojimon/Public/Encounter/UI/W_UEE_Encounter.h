// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Mud/Components/MonsterType/C_UEE_MonsterType.h"
#include "UObject/Object.h"
#include "W_UEE_Encounter.generated.h"

/**
 * 
 */
UCLASS()
class UEEMOJIMON_API UW_UEE_Encounter : public UUserWidget
{

	
public:
	GENERATED_BODY()

	UFUNCTION()
	void InitializeMonster(EMonsterType Monster);

	
};
