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


FInstancedStruct UCED_UEE_Position::GetComponentFromEncodedData(const TArray<uint8>& EncodedValues)
{

	TArray<uint8> xBytes = TArray<uint8>();
	xBytes.SetNum(32);
	for (int i = 0; i < 32; ++i)
	{
		xBytes[i] = EncodedValues[i];
	}
	int32 x = UFL_UEM_HexConversions::GetNumberFromBytes(xBytes);


	TArray<uint8> yBytes = TArray<uint8>();
	yBytes.SetNum(32);
	for (int i = 0; i < 32; ++i)
	{
		yBytes[i] = EncodedValues[i + 32];
	}
	int32 y = UFL_UEM_HexConversions::GetNumberFromBytes(yBytes);
	
	
	FC_UEE_Position Position = FC_UEE_Position(x,y);

	
	FInstancedStruct PositionComponent;
	PositionComponent.InitializeAs<FC_UEE_Position>(Position);
	return PositionComponent;
}
