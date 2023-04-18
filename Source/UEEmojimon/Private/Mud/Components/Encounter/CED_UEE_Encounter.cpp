// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Components/Encounter/CED_UEE_Encounter.h"
#include "Mud/Components/Encounter/C_UEE_Encounter.h"

FInstancedStruct UCED_UEE_Encounter::GetInitializedComponentInstancedStruct()
{
	FInstancedStruct CounterComponent;
	CounterComponent.InitializeAs<FC_UEE_Encounter>();
	return CounterComponent;
}
