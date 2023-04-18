// Fill out your copyright notice in the Description page of Project Settings.


#include "MapVisuals/Systems/SetupMapVisuals/S_UEE_SetupMapVisuals_OnMapConfig.h"

#include "Core/Component/Messages/ComponentSet/CF_ComponentSetMessage.h"
#include "EventSystem/StaticFuntionLibrary/CF_EventStatics.h"
#include "EventSystem/Subsystems/S_CF_Event.h"
#include "Group/StaticFuntionLibrary/CF_GroupsStatics.h"
#include "MapVisuals/Components/MapStartWorldPosition/C_UEE_MapStartPositionReferenceActor.h"
#include "MapVisuals/Components/MapVisualSettings/C_UEE_MapVisualSettings.h"
#include "MapVisuals/Components/MapVisualsInLevel/C_UEE_MapVisualsInLevel.h"
#include "Mud/Components/MapConfig/C_UEE_MapConfig.h"

void US_UEE_SetupMapVisuals_OnMapConfig::Initialize(FSubsystemCollectionBase& Collection)
{

	Super::Initialize(Collection);
	Collection.InitializeDependency(US_CF_Event::StaticClass());

	

	UCF_EventStatics::AddLambdaListener<FCF_ComponentSetMessageBase,FC_UEE_MapConfig>(this,
		[this](const UObject* Invoker,const FCF_ComponentSetMessageBase MapConfigComponentSet)
	{
		OnMapConfigComponentSet(MapConfigComponentSet);
	});
	
}

void US_UEE_SetupMapVisuals_OnMapConfig::OnMapConfigComponentSet(
	const FCF_ComponentSetMessageBase MapConfigComponentSet)
{
	FC_UEE_MapConfig MapConfig = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_MapConfig>(this);
	FC_UEE_MapVisualSettings MapVisualSettings = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_MapVisualSettings>(this);
	FC_UEE_MapStartPositionReferenceActor MapStartPositionReferenceActor = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_MapStartPositionReferenceActor>(this);

	FC_UEE_MapVisualsInLevel MapVisualsInLevel;
	if(UCF_GroupsStatics::DoesSingletonComponentExist<FC_UEE_MapVisualsInLevel>(this))
	{
		MapVisualsInLevel = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_MapVisualsInLevel>(this);
		if(MapVisualsInLevel.MapVisualActors.Num() > 0)
		{
			for (int i = 0; i < MapVisualsInLevel.MapVisualActors.Num(); ++i)
			{
				if(MapVisualsInLevel.MapVisualActors[i] != nullptr)
					MapVisualsInLevel.MapVisualActors[i]->Destroy();
			}	
		}	
	}
	MapVisualsInLevel.MapVisualActors.SetNum(MapConfig.Terrains.Num());

	for (int i = 0; i < MapConfig.Terrains.Num() ; ++i)
	{
		MapVisualsInLevel.MapVisualActors[i] = GetWorld()->SpawnActor(MapVisualSettings.TerrainVisuals[MapConfig.Terrains[i]]);
		FVector WorldLocation = MapStartPositionReferenceActor.MapStartPositionReferenceActor->GetActorLocation();
		int32 x = i % MapConfig.Width;
		int32 y = i / MapConfig.Width;
		WorldLocation = WorldLocation + FVector(100 * x,100 * y,0);
		MapVisualsInLevel.MapVisualActors[i]->SetActorLocation(WorldLocation);
	}
	if(UCF_GroupsStatics::DoesSingletonComponentExist<FC_UEE_MapVisualsInLevel>(this))
	{
		UCF_GroupsStatics::SetSingletonComponent<FC_UEE_MapVisualsInLevel>(this,MapVisualsInLevel);	
	}
	else
	{
		const FCF_Context MapVisualContext = UCF_Statics::CreateNewContext(this);
		UCF_Statics::SetComponentOfContextId<FC_UEE_MapVisualsInLevel>(this,MapVisualContext.ContextId,MapVisualsInLevel);
	}
	
	
	
	
	
}
