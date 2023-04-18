// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "S_UEE_UpdateLocalPlayer.generated.h"


UCLASS()
class UEEMOJIMON_API US_UEE_UpdateLocalPlayer : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION()
	void OnWalletComponentSet(const FCF_ComponentSetMessageBase WalletComponentSet);

	UFUNCTION()
	void OnPlayerComponentSet(const FCF_ComponentSetMessageBase PlayerComponentSet);
};
