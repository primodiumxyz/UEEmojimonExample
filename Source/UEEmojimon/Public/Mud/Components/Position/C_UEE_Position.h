// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Contract/Components/BaseComponents/Coord/C_UEM_Coord.h"
#include "Core/Component/CF_Component.h"
#include "UObject/Object.h"
#include "C_UEE_Position.generated.h"


USTRUCT(BlueprintType)
struct UEEMOJIMON_API FC_UEE_Position : public FC_UEM_Coord
{
	FC_UEE_Position() = default;

	FC_UEE_Position(const int32 _x, const int32 _y)
		: FC_UEM_Coord(_x, _y)
	{
	}

	GENERATED_BODY()
};
