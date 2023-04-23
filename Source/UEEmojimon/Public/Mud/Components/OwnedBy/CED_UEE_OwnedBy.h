// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Contract/Components/CED_UEM_ComponentBase.h"
#include "Contract/Components/BaseComponents/UInt256/CED_UEM_Uint256.h"
#include "UObject/Object.h"
#include "CED_UEE_OwnedBy.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class UEEMOJIMON_API UCED_UEE_OwnedBy : public UCED_UEM_Uint256
{
	GENERATED_BODY()
protected:
	virtual FInstancedStruct GetInitializedComponentInstancedStruct() override;

};
