// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Component/CF_Component.h"
#include "MapVisuals/Components/Visual/C_UEE_Visual.h"
#include "UObject/Object.h"
#include "C_UEE_PlayerVisual.generated.h"

USTRUCT(BlueprintType)
struct UEEMOJIMON_API FC_UEE_PlayerVisual : public FC_UEE_Visual
{
	GENERATED_BODY()
	FC_UEE_PlayerVisual()
	{
		VisualActor = nullptr;
	}

	FC_UEE_PlayerVisual(AActor* _VisualActor)
	{
		VisualActor = _VisualActor;
	}
};
