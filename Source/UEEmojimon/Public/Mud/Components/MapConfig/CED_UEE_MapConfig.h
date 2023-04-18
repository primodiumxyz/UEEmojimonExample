// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CED_UEM_ComponentBase.h"
#include "UObject/Object.h"
#include "CED_UEE_MapConfig.generated.h"



UCLASS(Blueprintable,BlueprintType)
class UEEMOJIMON_API UCED_UEE_MapConfig : public UCED_UEM_ComponentBase
{
	GENERATED_BODY()
protected:
	virtual FInstancedStruct GetInitializedComponentInstancedStruct() override;



	virtual FInstancedStruct GetComponentFromEncodedData(const TArray<uint8>& EncodedValues) override;
	
};
