// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Contract/Components/BaseComponents/Bool/CED_UEM_Bool.h"
#include "UObject/Object.h"
#include "CED_UEE_Obstruction.generated.h"

/**
 * 
 */


UCLASS(Blueprintable,BlueprintType)
class UEEMOJIMON_API UCED_UEE_Obstruction : public UCED_UEM_Bool
{
	GENERATED_BODY()
protected:
	virtual FInstancedStruct GetInitializedComponentInstancedStruct() override;

};
