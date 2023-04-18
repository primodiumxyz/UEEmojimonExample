// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnrealGameplayFramework/ContextWrapper/BaseClasses/Actor/CF_WrapperActor.h"
#include "CW_UEE_MapWorldStartPositionReference.generated.h"

UCLASS()
class UEEMOJIMON_API ACW_UEE_MapWorldStartPositionReference : public ACF_WrapperActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
