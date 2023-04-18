﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "S_UEE_UpdatePlayerVisualPosition.generated.h"


UCLASS()
class UEEMOJIMON_API US_UEE_UpdatePlayerVisualPosition : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION()
	void OnPositionComponentSet(const FCF_ComponentSetMessageBase PositionComponentSet);
};
