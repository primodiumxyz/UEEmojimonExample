// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Systems/UpdatePlayerVisual/S_UEE_UpdatePlayerVisual.h"

#include "Core/StaticFunctionLibrary/CF_Statics.h"
#include "Core/Subsystems/S_CF_Core.h"
#include "EventSystem/StaticFuntionLibrary/CF_EventStatics.h"
#include "EventSystem/Subsystems/S_CF_Event.h"
#include "Group/StaticFuntionLibrary/CF_GroupsStatics.h"
#include "MapVisuals/Components/MapStartWorldPosition/C_UEE_MapStartPositionReferenceActor.h"
#include "Mud/Components/MapConfig/C_UEE_MapConfig.h"
#include "Mud/Components/Position/C_UEE_Position.h"
#include "Player/Components/IsLocalPlayer/C_UEE_IsLocalPlayer.h"
#include "Player/Components/PlayerVisual/C_UEE_PlayerVisual.h"
#include "Player/Components/PlayerVisualSettings/C_UEE_PlayerVisualSettings.h"
#include "Player/Systems/InitializeWallet/S_UEE_InitializePlayerWallet.h"
#include "Sync/Systems/S_UEM_SyncInitialize.h"
#include "Wallet/Systems/S_UEM_Wallet_Initialize.h"
#include "WorldSettings/Systems/S_UEM_LoadWorldSettings.h"

void US_UEE_UpdatePlayerVisual::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_UEM_LoadWorldSettings::StaticClass());
	Collection.InitializeDependency(US_UEM_Wallet_Initialize::StaticClass());
	Collection.InitializeDependency(US_UEE_InitializePlayerWallet::StaticClass());
	Collection.InitializeDependency(US_UEM_SyncInitialize::StaticClass());
	
	
	UCF_EventStatics::AddLambdaListener<FCF_ComponentSetMessageBase,FC_UEE_IsLocalPlayer>(this,
		[this](const UObject* Invoker,const FCF_ComponentSetMessageBase IsLocalPlayerComponentSet)
	{
		OnLocalPlayerComponentSet(IsLocalPlayerComponentSet);
	});


	UCF_EventStatics::AddLambdaListener<FCF_ComponentRemovedMessageBase,FC_UEE_IsLocalPlayer>(this,
		[this](const UObject* Invoker,const FCF_ComponentRemovedMessageBase IsLocalPlayerComponentRemoved)
	{
		OnLocalPlayerComponentRemoved(IsLocalPlayerComponentRemoved);
	});

}

void US_UEE_UpdatePlayerVisual::OnLocalPlayerComponentSet(const FCF_ComponentSetMessageBase LocalPlayerComponentSet)
{
	
	if(UCF_Statics::HasComponentForContextId_Template<FC_UEE_PlayerVisual>(this,LocalPlayerComponentSet.ContextId))
	{

		const FC_UEE_MapConfig MapConfig = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_MapConfig>(this);
		const FC_UEE_PlayerVisualSettings PlayerVisualSettings = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_PlayerVisualSettings>(this);
		const FC_UEE_MapStartPositionReferenceActor MapStartPositionReferenceActor = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_MapStartPositionReferenceActor>(this);

		const FC_UEE_Position NewLocalPlayerPosition = UCF_Statics::GetComponentOfContextId<FC_UEE_Position>(this,LocalPlayerComponentSet.ContextId);
		FC_UEE_PlayerVisual NewLocalPlayerVisual = UCF_Statics::GetComponentOfContextId<FC_UEE_PlayerVisual>(this,LocalPlayerComponentSet.ContextId);
		NewLocalPlayerVisual.VisualActor->Destroy();
		NewLocalPlayerVisual.VisualActor = nullptr;
		
		AActor* PlayerVisualActor = GetWorld()->SpawnActor(PlayerVisualSettings.LocalPlayerVisual);
		FVector WorldLocation = MapStartPositionReferenceActor.MapStartPositionReferenceActor->GetActorLocation();
		WorldLocation = WorldLocation + FVector(100 * NewLocalPlayerPosition.x,100 * NewLocalPlayerPosition.y,0);
		PlayerVisualActor->SetActorLocation(WorldLocation);
		NewLocalPlayerVisual.VisualActor = PlayerVisualActor;
		UCF_Statics::SetComponentOfContextId<FC_UEE_PlayerVisual>(this,LocalPlayerComponentSet.ContextId,NewLocalPlayerVisual);

		
	}
}

void US_UEE_UpdatePlayerVisual::OnLocalPlayerComponentRemoved(
	const FCF_ComponentRemovedMessageBase LocalPlayerComponentRemoved)
{

	const FC_UEE_MapConfig MapConfig = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_MapConfig>(this);
	const FC_UEE_PlayerVisualSettings PlayerVisualSettings = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_PlayerVisualSettings>(this);
	const FC_UEE_MapStartPositionReferenceActor MapStartPositionReferenceActor = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_MapStartPositionReferenceActor>(this);


	
	if(UCF_Statics::HasComponentForContextId_Template<FC_UEE_PlayerVisual>(this,LocalPlayerComponentRemoved.ContextId))
	{
		const FC_UEE_Position OldLocalPlayerPosition = UCF_Statics::GetComponentOfContextId<FC_UEE_Position>(this,LocalPlayerComponentRemoved.ContextId);
		FC_UEE_PlayerVisual OldLocalPlayerVisual = UCF_Statics::GetComponentOfContextId<FC_UEE_PlayerVisual>(this,LocalPlayerComponentRemoved.ContextId);
		OldLocalPlayerVisual.VisualActor->Destroy();
		OldLocalPlayerVisual.VisualActor = nullptr;


		AActor* PlayerVisualActor = GetWorld()->SpawnActor(PlayerVisualSettings.NonLocalPlayerVisual);
		FVector WorldLocation = MapStartPositionReferenceActor.MapStartPositionReferenceActor->GetActorLocation();
		WorldLocation = WorldLocation + FVector(100 * OldLocalPlayerPosition.x,100 * OldLocalPlayerPosition.y,0);
		PlayerVisualActor->SetActorLocation(WorldLocation);
		OldLocalPlayerVisual.VisualActor = PlayerVisualActor;
		UCF_Statics::SetComponentOfContextId<FC_UEE_PlayerVisual>(this,LocalPlayerComponentRemoved.ContextId,OldLocalPlayerVisual);

		
	}
}
