// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Systems/UpdatePlayerVisualPosition/S_UEE_UpdatePlayerVisualPosition.h"

#include "Core/Component/Messages/ComponentSet/CF_ComponentSetMessage.h"
#include "Core/StaticFunctionLibrary/CF_Statics.h"
#include "EventSystem/StaticFuntionLibrary/CF_EventStatics.h"
#include "EventSystem/Subsystems/S_CF_Event.h"
#include "Group/StaticFuntionLibrary/CF_GroupsStatics.h"
#include "MapVisuals/Components/MapStartWorldPosition/C_UEE_MapStartPositionReferenceActor.h"
#include "Mud/Components/MapConfig/C_UEE_MapConfig.h"
#include "Mud/Components/Player/C_UEE_Player.h"
#include "Mud/Components/Position/C_UEE_Position.h"
#include "Player/Components/PlayerVisual/C_UEE_PlayerVisual.h"
#include "Player/Systems/AddVisualForPlayer/S_UEE_AddVisualForPlayer.h"
#include "Player/Systems/LoadPlayerVisual/S_UEE_LoadPlayerVisualSettings.h"


void US_UEE_UpdatePlayerVisualPosition::Initialize(FSubsystemCollectionBase& Collection)
{

	Super::Initialize(Collection);
	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_UEE_LoadPlayerVisualSettings::StaticClass());
	Collection.InitializeDependency(US_UEE_AddVisualForPlayer::StaticClass());

	

	UCF_EventStatics::AddLambdaListener<FCF_ComponentSetMessageBase,FC_UEE_Position>(this,
		[this](const UObject* Invoker,const FCF_ComponentSetMessageBase MovableComponentSet)
	{
		OnPositionComponentSet(MovableComponentSet);
	});


	
}

void US_UEE_UpdatePlayerVisualPosition::OnPositionComponentSet(
	const FCF_ComponentSetMessageBase MovableComponentSet)
{
	if(!UCF_Statics::HasComponentForContextId_Template<FC_UEE_Player>(this,MovableComponentSet.ContextId))
	{
		//GEngine->AddOnScreenDebugMessage(-1, 60, FColor::Red,"Entity Doesnt have Player" );
		return;
	}

	if(!UCF_Statics::HasComponentForContextId_Template<FC_UEE_PlayerVisual>(this,MovableComponentSet.ContextId))
	{
		//GEngine->AddOnScreenDebugMessage(-1, 60, FColor::Red,"Entity Doesnt have Visual" );
		return;
	}
	
	
	const FC_UEE_MapConfig MapConfig = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_MapConfig>(this);
	const FC_UEE_MapStartPositionReferenceActor MapStartPositionReferenceActor =
		UCF_GroupsStatics::GetSingletonComponent<FC_UEE_MapStartPositionReferenceActor>(this);

	
	const FC_UEE_Position PlayerPosition = UCF_Statics::GetComponentOfContextId<FC_UEE_Position>(this,MovableComponentSet.ContextId);
	const FC_UEE_PlayerVisual PlayerVisualComponent = UCF_Statics::GetComponentOfContextId<FC_UEE_PlayerVisual>(this,MovableComponentSet.ContextId);
	
	FVector WorldLocation = MapStartPositionReferenceActor.MapStartPositionReferenceActor->GetActorLocation();
	WorldLocation = WorldLocation + FVector(100 * PlayerPosition.x,100 * PlayerPosition.y,0);
	PlayerVisualComponent.VisualActor->SetActorLocation(WorldLocation);
}
