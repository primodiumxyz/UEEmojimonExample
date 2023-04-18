// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Components/Counter/CED_UEE_Counter.h"

#include "Mud/Components/Counter/C_UEE_Counter.h"

FInstancedStruct UCED_UEE_Counter::GetInitializedComponentInstancedStruct()
{
	FInstancedStruct CounterComponent;
	CounterComponent.InitializeAs<FC_UEE_Counter>();
	return CounterComponent;
}
