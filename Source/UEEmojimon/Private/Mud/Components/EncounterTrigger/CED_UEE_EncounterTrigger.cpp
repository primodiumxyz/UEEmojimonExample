// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Components/EncounterTrigger/CED_UEE_EncounterTrigger.h"

#include "Mud/Components/EncounterTrigger/C_UEE_EncounterTrigger.h"

FInstancedStruct UCED_UEE_EncounterTrigger::GetInitializedComponentInstancedStruct()
{
	FInstancedStruct CounterComponent;
	CounterComponent.InitializeAs<FC_UEE_EncounterTrigger>();
	return CounterComponent;
}
