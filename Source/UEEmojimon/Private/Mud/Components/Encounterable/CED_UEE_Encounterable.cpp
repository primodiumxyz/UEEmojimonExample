// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Components/Encounterable/CED_UEE_Encounterable.h"
#include "Mud/Components/Encounterable/C_UEE_Encounterable.h"


FInstancedStruct UCED_UEE_Encounterable::GetInitializedComponentInstancedStruct()
{
	FInstancedStruct EncounterableComponent;
	EncounterableComponent.InitializeAs<FC_UEE_Encounterable>();
	return EncounterableComponent;
}
