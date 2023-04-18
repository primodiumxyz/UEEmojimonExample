// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Components/MapConfig/CED_UEE_MapConfig.h"

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
	
	TArray<uint8> widthBytes = TArray<uint8>();
	widthBytes.SetNum(32);
	for (int i = 0; i < 32; ++i)
	{
		widthBytes[i] = EncodedValues[i];
	}
	int32 Width = UFL_UEM_HexConversions::GetNumberFromBytes(widthBytes);


	TArray<uint8> heightBytes = TArray<uint8>();
	heightBytes.SetNum(32);
	for (int i = 0; i < 32; ++i)
	{
		heightBytes[i] = EncodedValues[i + 32];
	}
	int32 Height = UFL_UEM_HexConversions::GetNumberFromBytes(heightBytes);

	TArray<uint8> unknownDataBytes = TArray<uint8>();
	unknownDataBytes.SetNum(32);
	for (int i = 0; i < 32; ++i)
	{
		unknownDataBytes[i] = EncodedValues[i + 64];
	}
	int32 UnknownData = UFL_UEM_HexConversions::GetNumberFromBytes(unknownDataBytes);
	
	TArray<uint8> terrainByteArraySizeBytes = TArray<uint8>();
	terrainByteArraySizeBytes.SetNum(32);
	for (int i = 0; i < 32; ++i)
	{
		terrainByteArraySizeBytes[i] = EncodedValues[i + 96];
	}
	int32 TerrainByteArraySize = UFL_UEM_HexConversions::GetNumberFromBytes(terrainByteArraySizeBytes);

	TArray<uint8> terrainByteArray = TArray<uint8>();
	terrainByteArray.SetNum(TerrainByteArraySize);
	for (int i = 0; i < TerrainByteArraySize; ++i)
	{
		terrainByteArray[i] = EncodedValues[i + 128];
	}
	

	
	FInstancedStruct MapConfigInstancedStruct = GetInitializedComponentInstancedStruct();
	FC_UEE_MapConfig& MapConfigComponent = MapConfigInstancedStruct.GetMutable<FC_UEE_MapConfig>();
	MapConfigComponent.Width = Width;
	MapConfigComponent.Height = Height;
	MapConfigComponent.Terrains.SetNum(terrainByteArray.Num());
	for (int i = 0; i < terrainByteArray.Num(); ++i)
	{
		MapConfigComponent.Terrains[i] = static_cast<EMapConfig_Terrain>(terrainByteArray[i]);
	}
	return MapConfigInstancedStruct;
}
