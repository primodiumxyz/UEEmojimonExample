// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Components/Movable/CED_UEE_Movable.h"

#include "Mud/Components/Movable/C_UEE_Movable.h"


FInstancedStruct UCED_UEE_Movable::GetInitializedComponentInstancedStruct()
{
	FInstancedStruct MovableComponent;
	MovableComponent.InitializeAs<FC_UEE_Movable>();
	return MovableComponent;
}
