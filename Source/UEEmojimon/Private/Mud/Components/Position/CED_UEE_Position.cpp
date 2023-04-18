// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Components/Position/CED_UEE_Position.h"

#include "Hex/FL_UEM_HexConversions.h"
#include "StructUtils/Public/InstancedStruct.h"
#include "Misc/DefaultValueHelper.h"
#include "Mud/Components/Position/C_UEE_Position.h"

FInstancedStruct UCED_UEE_Position::GetInitializedComponentInstancedStruct()
{
	FInstancedStruct PositionComponent;
	PositionComponent.InitializeAs<FC_UEE_Position>();
	return PositionComponent;
}

