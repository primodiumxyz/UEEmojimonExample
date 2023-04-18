// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Systems/SED_UEM_Base.h"
#include "UObject/Object.h"
#include "SED_UEM_Move.generated.h"


UCLASS()
class UEEMOJIMON_API USED_UEM_Move : public USED_UEM_Base
{
	GENERATED_BODY()


	virtual const TArray<FString> GetStringArguments(FInstancedStruct SystemArgumentsStruct) override;

	virtual const FString GetEncodedArguments(FInstancedStruct SystemArgumentsStruct) override;
};
