// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Components/OwnedBy/CED_UEE_OwnedBy.h"

#include "Mud/Components/OwnedBy/C_UEE_OwnedBy.h"


FInstancedStruct UCED_UEE_OwnedBy::GetInitializedComponentInstancedStruct()
{
	FInstancedStruct PositionComponent;
	PositionComponent.InitializeAs<FC_UEE_OwnedBy>();
	return PositionComponent;
}
