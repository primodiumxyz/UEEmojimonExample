// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Systems/Move/SED_UEM_Move.h"

#include "Encoding/FL_UEM_Encode.h"
#include "Mud/Systems/Move/Messages/M_UEE_Move_Execute.h"



const TArray<FString> USED_UEM_Move::GetStringArguments(FInstancedStruct SystemArgumentsStruct)
{
	
	const FM_UEE_Move_Execute Move_Execute = SystemArgumentsStruct.Get<FM_UEE_Move_Execute>();

	TArray<FString> Arguments =TArray<FString>();
	Arguments.SetNum(2);
	Arguments[0] = UFL_UEM_Encode::EncodeNumber(Move_Execute.TargetPosition.x);
	Arguments[1] = UFL_UEM_Encode::EncodeNumber(Move_Execute.TargetPosition.y);
	return Arguments;
}

const FString USED_UEM_Move::GetEncodedArguments(FInstancedStruct SystemArgumentsStruct)
{
	const FM_UEE_Move_Execute Move_Execute = SystemArgumentsStruct.Get<FM_UEE_Move_Execute>();
	return UFL_UEM_Encode::EncodeNumber(Move_Execute.TargetPosition.x) + UFL_UEM_Encode::EncodeNumber(Move_Execute.TargetPosition.y);
}



