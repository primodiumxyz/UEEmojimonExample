// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "S_UEE_UpdatePlayerWallet.generated.h"


UCLASS()
class UEEMOJIMON_API US_UEE_UpdatePlayerWallet : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION()
	void OnWalletNameComponentSet(const FCF_ComponentSetMessageBase WalletNameComponentSet);
};
