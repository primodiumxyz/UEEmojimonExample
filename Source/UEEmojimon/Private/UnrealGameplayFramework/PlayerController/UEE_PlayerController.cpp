// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealGameplayFramework/PlayerController/UEE_PlayerController.h"

#include "Core/StaticFunctionLibrary/CF_Statics.h"
#include "EventSystem/StaticFuntionLibrary/CF_EventStatics.h"
#include "Group/StaticFuntionLibrary/CF_GroupsStatics.h"
#include "Mud/Components/Movable/C_UEE_Movable.h"
#include "Player/Components/IsLocalPlayer/C_UEE_IsLocalPlayer.h"
#include "Player/Components/WalletName/C_UEE_PlayerWalletName.h"
#include "Sync/Components/MudEntityIdMapping/C_UEM_MudEntityIdMapping.h"
#include "Wallet/Components/Wallet/C_UEM_WalletAddress.h"


// Sets default values
AUEE_PlayerController::AUEE_PlayerController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


void AUEE_PlayerController::TryMove(FM_UEE_Move_Execute Move_Execute)
{

	FC_UEM_MudEntityIdMapping MudEntityIdMapping = UCF_GroupsStatics::GetSingletonComponent<FC_UEM_MudEntityIdMapping>(this);
	FC_UEM_WalletAddress Wallet = UCF_GroupsStatics::GetSingletonComponent<FC_UEM_WalletAddress>(this);

	if(MudEntityIdMapping.MudEntityIdToLocalContextId.Contains(Wallet.EthWalletAddress))
	{
		MudPlayerContextID = MudEntityIdMapping.MudEntityIdToLocalContextId[Wallet.EthWalletAddress];
	}


	const FC_UEE_Position CurrentPosition =UCF_Statics::GetComponentOfContextId<FC_UEE_Position>(this,MudPlayerContextID);
	const FM_UEE_Move_Execute TargetMove_Execute =FM_UEE_Move_Execute(
		FC_UEE_Position(
			Move_Execute.TargetPosition.x + CurrentPosition.x,
			Move_Execute.TargetPosition.y + CurrentPosition.y));
	UCF_EventStatics::FireEvent_Template<FM_UEE_Move_Execute>(this,TargetMove_Execute);
}

void AUEE_PlayerController::TrySelectStartPosition(FM_UEE_JoinGame_Execute JoinGame_Execute)
{
	UCF_EventStatics::FireEvent_Template<FM_UEE_JoinGame_Execute>(this,JoinGame_Execute);
}

void AUEE_PlayerController::UpdateWallet(FString WalletName)
{
	if(UCF_GroupsStatics::DoesSingletonComponentExist<FC_UEE_PlayerWalletName>(this))
		UCF_GroupsStatics::SetSingletonComponent<FC_UEE_PlayerWalletName>(this,FC_UEE_PlayerWalletName(WalletName));
}

void AUEE_PlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(!UCF_GroupsStatics::DoesSingletonComponentExist<FC_UEE_IsLocalPlayer>(this))
		return;
	

	int32 LocalPlayerContextId = UCF_GroupsStatics::GetSingletonComponentContextId<FC_UEE_IsLocalPlayer >(this);

	if(!UCF_Statics::HasComponentForContextId_Template<FC_UEE_Movable>(this,LocalPlayerContextId))
	{
		OnSelectStartPosition();
	}
	else if(UCF_Statics::GetComponentOfContextId<FC_UEE_Movable>(this,LocalPlayerContextId).Value)
	{
		OnSelectMovePosition();
	}
	else
	{
		OnSelectEncounterStrategy();
	}
	
}

