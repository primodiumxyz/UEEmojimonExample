// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Components/MonsterType/CED_UEE_MonsterType.h"

#include "Mud/Components/MonsterType/C_UEE_MonsterType.h"


FInstancedStruct UCED_UEE_MonsterType::GetInitializedComponentInstancedStruct()
{
	FInstancedStruct CounterComponent;
	CounterComponent.InitializeAs<FC_UEE_MonsterType>();
	return CounterComponent;
}
