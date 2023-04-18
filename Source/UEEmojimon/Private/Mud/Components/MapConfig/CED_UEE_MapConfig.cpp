// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Components/MapConfig/CED_UEE_MapConfig.h"

#include "Encoding/FL_UEM_Encode.h"
#include "Hex/FL_UEM_HexConversions.h"
#include "Misc/DefaultValueHelper.h"
#include "Mud/Components/MapConfig/C_UEE_MapConfig.h"


FInstancedStruct UCED_UEE_MapConfig::GetInitializedComponentInstancedStruct()
{
	FInstancedStruct PositionComponent;
	PositionComponent.InitializeAs<FC_UEE_MapConfig>();
	return PositionComponent;
}


FInstancedStruct UCED_UEE_MapConfig::GetComponentFromEncodedData(const TArray<uint8>& EncodedValues)
{
	FInstancedStruct MapConfigInstancedStruct = GetInitializedComponentInstancedStruct();
	FC_UEE_MapConfig& MapConfigComponent = MapConfigInstancedStruct.GetMutable<FC_UEE_MapConfig>();
	
	MapConfigComponent.Width = UFL_UEM_Encode::DecodeNumber(EncodedValues);
	MapConfigComponent.Height = UFL_UEM_Encode::DecodeNumber(EncodedValues,32);;
	
	TArray<uint8> terrainByteArray = UFL_UEM_Encode::DecodeBytes(EncodedValues,64);;
	MapConfigComponent.Terrains.SetNum(terrainByteArray.Num());
	for (int i = 0; i < terrainByteArray.Num(); ++i)
	{
		MapConfigComponent.Terrains[i] = static_cast<EMapConfig_Terrain>(terrainByteArray[i]);
	}
	return MapConfigInstancedStruct;
}
