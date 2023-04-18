// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventSystem/Message/CF_Message.h"
#include "Mud/Components/Position/C_UEE_Position.h"
#include "UObject/Object.h"
#include "M_UEE_Move_Execute.generated.h"


USTRUCT(BlueprintType)
struct UEEMOJIMON_API FM_UEE_Move_Execute : public FCF_Message
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere )
	FC_UEE_Position TargetPosition;

	

	FM_UEE_Move_Execute()
	{
		TargetPosition =FC_UEE_Position(0,0); 
	}

	FM_UEE_Move_Execute(FC_UEE_Position _StartPosition)
	{
		TargetPosition = _StartPosition;
	}
	
	
};