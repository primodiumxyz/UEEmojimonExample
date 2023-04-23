// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Contract/Components/BaseComponents/UInt32/CED_UEM_UInt32.h"
#include "UObject/Object.h"
#include "CED_UEE_MonsterType.generated.h"



UCLASS(Blueprintable,BlueprintType)
class UEEMOJIMON_API UCED_UEE_MonsterType : public UCED_UEM_UInt32
{
	GENERATED_BODY()
protected:
	virtual FInstancedStruct GetInitializedComponentInstancedStruct() override;

};