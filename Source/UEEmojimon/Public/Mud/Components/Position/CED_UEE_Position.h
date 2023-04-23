// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Contract/Components/CED_UEM_ComponentBase.h"
#include "Contract/Components/BaseComponents/Coord/CED_UEM_Coord.h"
#include "UObject/Object.h"
#include "CED_UEE_Position.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class UEEMOJIMON_API UCED_UEE_Position : public UCED_UEM_Coord
{
	GENERATED_BODY()
protected:
	virtual FInstancedStruct GetInitializedComponentInstancedStruct() override;


	
};
