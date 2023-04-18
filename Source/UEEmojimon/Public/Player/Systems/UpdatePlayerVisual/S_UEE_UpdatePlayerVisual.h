// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Component/Messages/ComponentSet/CF_ComponentSetMessage.h"
#include "Core/Component/Messages/ComponentRemoved/CF_ComponentRemovedMessage.h"
#include "UObject/Object.h"
#include "S_UEE_UpdatePlayerVisual.generated.h"


UCLASS()
class UEEMOJIMON_API US_UEE_UpdatePlayerVisual : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION()
	void OnLocalPlayerComponentSet(const FCF_ComponentSetMessageBase LocalPlayerComponentSet);

	UFUNCTION()
	void OnLocalPlayerComponentRemoved(const FCF_ComponentRemovedMessageBase LocalPlayerComponentRemoved);
};
