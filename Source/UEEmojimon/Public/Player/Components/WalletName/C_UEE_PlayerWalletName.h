// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Component/CF_Component.h"
#include "UObject/Object.h"
#include "C_UEE_PlayerWalletName.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct UEEMOJIMON_API FC_UEE_PlayerWalletName : public FCF_Component
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FString WalletName = "DefaultWallet";
	
	FC_UEE_PlayerWalletName()
	{
		WalletName = "DefaultWallet";
	}

	FC_UEE_PlayerWalletName(FString _WalletName)
	{
		WalletName = _WalletName;
	}
};
