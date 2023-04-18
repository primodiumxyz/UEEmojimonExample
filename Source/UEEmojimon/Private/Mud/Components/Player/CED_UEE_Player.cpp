// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Components/Player/CED_UEE_Player.h"

#include "Mud/Components/Player/C_UEE_Player.h"


FInstancedStruct UCED_UEE_Player::GetInitializedComponentInstancedStruct()
{
	FInstancedStruct PlayerComponent;
	PlayerComponent.InitializeAs<FC_UEE_Player>();
	return PlayerComponent;
}
