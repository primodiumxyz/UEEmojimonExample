// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Systems/JoinGame/SED_UEM_JoinGame.h"

#include "Encoding/FL_UEM_Encode.h"
#include "Mud/Systems/JoinGame/Messages/M_UEE_JoinGame_Execute.h"



const TArray<FString> USED_UEM_JoinGame::GetStringArguments(FInstancedStruct SystemArgumentsStruct)
{
	TArray<FString> Arguments =TArray<FString>();
	Arguments.SetNum(2);
	const FM_UEE_JoinGame_Execute JoinGame_Execute = SystemArgumentsStruct.Get<FM_UEE_JoinGame_Execute>();
	Arguments[0] = UFL_UEM_Encode::EncodeNumber(JoinGame_Execute.StartPosition.x);
	Arguments[1] = UFL_UEM_Encode::EncodeNumber(JoinGame_Execute.StartPosition.y);
	
	return Arguments;
}

const FString USED_UEM_JoinGame::GetEncodedArguments(FInstancedStruct SystemArgumentsStruct)
{
	const FM_UEE_JoinGame_Execute JoinGame = SystemArgumentsStruct.Get<FM_UEE_JoinGame_Execute>();
	return UFL_UEM_Encode::EncodeNumber(JoinGame.StartPosition.x) + UFL_UEM_Encode::EncodeNumber(JoinGame.StartPosition.y, false);
}
