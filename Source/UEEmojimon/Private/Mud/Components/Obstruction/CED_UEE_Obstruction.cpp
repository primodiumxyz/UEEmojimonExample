// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Components/Obstruction/CED_UEE_Obstruction.h"

#include "Mud/Components/Obstruction/C_UEE_Obstruction.h"


FInstancedStruct UCED_UEE_Obstruction::GetInitializedComponentInstancedStruct()
{
	FInstancedStruct ObstructionComponent;
	ObstructionComponent.InitializeAs<FC_UEE_Obstruction>();
	return ObstructionComponent;
}
