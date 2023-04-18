// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Systems/AddVisualForPlayer/S_UEE_AddVisualForPlayer.h"
#include "Core/Component/Messages/ComponentSet/CF_ComponentSetMessage.h"
#include "EventSystem/StaticFuntionLibrary/CF_EventStatics.h"
#include "EventSystem/Subsystems/S_CF_Event.h"
#include "Group/StaticFuntionLibrary/CF_GroupsStatics.h"
#include "MapVisuals/Components/MapStartWorldPosition/C_UEE_MapStartPositionReferenceActor.h"
#include "MapVisuals/Components/MapVisualSettings/C_UEE_MapVisualSettings.h"
#include "Mud/Components/Encounterable/C_UEE_Encounterable.h"
#include "Mud/Components/MapConfig/C_UEE_MapConfig.h"
#include "Mud/Components/Movable/C_UEE_Movable.h"
#include "Mud/Components/Player/C_UEE_Player.h"
#include "Mud/Components/Position/C_UEE_Position.h"
#include "Player/Components/IsLocalPlayer/C_UEE_IsLocalPlayer.h"
#include "Player/Components/PlayerVisual/C_UEE_PlayerVisual.h"
#include "Player/Components/PlayerVisualSettings/C_UEE_PlayerVisualSettings.h"
#include "Player/Systems/LoadPlayerVisual/S_UEE_LoadPlayerVisualSettings.h"

void US_UEE_AddVisualForPlayer::Initialize(FSubsystemCollectionBase& Collection)
{

	Super::Initialize(Collection);
	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_UEE_LoadPlayerVisualSettings::StaticClass());

	

	UCF_EventStatics::AddLambdaListener<FCF_ComponentSetMessageBase,FC_UEE_Position>(this,
		[this](const UObject* Invoker,const FCF_ComponentSetMessageBase MovableComponentSet)
	{
		OnMovableComponentSet(MovableComponentSet);
	});

	UCF_EventStatics::AddLambdaListener<FCF_ComponentSetMessageBase,FC_UEE_Player>(this,
		[this](const UObject* Invoker,const FCF_ComponentSetMessageBase MovableComponentSet)
	{
		OnMovableComponentSet(MovableComponentSet);
	});

	
}

void US_UEE_AddVisualForPlayer::OnMovableComponentSet(
	const FCF_ComponentSetMessageBase MovableComponentSet)
{
	if(!UCF_Statics::HasComponentForContextId_Template<FC_UEE_Player>(this,MovableComponentSet.ContextId))
	{
		//GEngine->AddOnScreenDebugMessage(-1, 60, FColor::Red,"Entity Doesnt have Player" );
		return;
	}
	
	if(!UCF_Statics::HasComponentForContextId_Template<FC_UEE_Position>(this,MovableComponentSet.ContextId))
	{
		//GEngine->AddOnScreenDebugMessage(-1, 60, FColor::Red,"Entity Doesnt have Position" );
		return;
	}

	if(UCF_Statics::HasComponentForContextId_Template<FC_UEE_PlayerVisual>(this,MovableComponentSet.ContextId))
	{
		//GEngine->AddOnScreenDebugMessage(-1, 60, FColor::Red,"Entity Already Has Visual" );
		return;
	}
	
	const FC_UEE_MapConfig MapConfig = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_MapConfig>(this);
	const FC_UEE_PlayerVisualSettings PlayerVisualSettings = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_PlayerVisualSettings>(this);
	const FC_UEE_MapStartPositionReferenceActor MapStartPositionReferenceActor = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_MapStartPositionReferenceActor>(this);

	
	const FC_UEE_Position PlayerPosition = UCF_Statics::GetComponentOfContextId<FC_UEE_Position>(this,MovableComponentSet.ContextId);

	TSubclassOf<AActor> PlayerVisualClass = UCF_Statics::HasComponentForContextId_Template<FC_UEE_IsLocalPlayer>(this,MovableComponentSet.ContextId) ?
		PlayerVisualSettings.LocalPlayerVisual : PlayerVisualSettings.NonLocalPlayerVisual;
	
	AActor* PlayerVisualActor = GetWorld()->SpawnActor(PlayerVisualClass);
	FVector WorldLocation = MapStartPositionReferenceActor.MapStartPositionReferenceActor->GetActorLocation();
	WorldLocation = WorldLocation + FVector(100 * PlayerPosition.x,100 * PlayerPosition.y,0);
	PlayerVisualActor->SetActorLocation(WorldLocation);

	UCF_Statics::SetComponentOfContextId<FC_UEE_PlayerVisual>(this,MovableComponentSet.ContextId,FC_UEE_PlayerVisual(PlayerVisualActor));
}
