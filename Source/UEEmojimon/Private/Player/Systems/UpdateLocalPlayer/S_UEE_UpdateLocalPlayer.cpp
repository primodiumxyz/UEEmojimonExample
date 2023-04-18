// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Systems/UpdateLocalPlayer/S_UEE_UpdateLocalPlayer.h"

#include "Core/Component/Messages/ComponentSet/CF_ComponentSetMessage.h"
#include "EventSystem/StaticFuntionLibrary/CF_EventStatics.h"
#include "EventSystem/Subsystems/S_CF_Event.h"
#include "Group/StaticFuntionLibrary/CF_GroupsStatics.h"
#include "Mud/Components/Player/C_UEE_Player.h"
#include "Player/Components/IsLocalPlayer/C_UEE_IsLocalPlayer.h"
#include "Player/Systems/InitializeWallet/S_UEE_InitializePlayerWallet.h"
#include "Sync/Components/MudEntityIdMapping/C_UEM_MudEntityIdMapping.h"
#include "Sync/Systems/S_UEM_SyncInitialize.h"
#include "Wallet/Components/Wallet/C_UEM_WalletAddress.h"
#include "Wallet/Systems/S_UEM_Wallet_Initialize.h"
#include "WorldSettings/Systems/S_UEM_LoadWorldSettings.h"

void US_UEE_UpdateLocalPlayer::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_UEM_LoadWorldSettings::StaticClass());
	Collection.InitializeDependency(US_UEM_Wallet_Initialize::StaticClass());
	Collection.InitializeDependency(US_UEE_InitializePlayerWallet::StaticClass());
	Collection.InitializeDependency(US_UEM_SyncInitialize::StaticClass());
	
	
	

	UCF_EventStatics::AddLambdaListener<FCF_ComponentSetMessageBase,FC_UEM_WalletAddress>(this,
		[this](const UObject* Invoker,const FCF_ComponentSetMessageBase WalletComponentSet)
	{
		OnWalletComponentSet(WalletComponentSet);
	});

	
	UCF_EventStatics::AddLambdaListener<FCF_ComponentSetMessageBase,FC_UEE_Player>(this,
		[this](const UObject* Invoker,const FCF_ComponentSetMessageBase PlayerComponentSet)
	{
		OnPlayerComponentSet(PlayerComponentSet);
	});

}


void US_UEE_UpdateLocalPlayer::OnPlayerComponentSet(const FCF_ComponentSetMessageBase PlayerComponentSet)
{
	const FC_UEM_WalletAddress Wallet = UCF_GroupsStatics::GetSingletonComponent<FC_UEM_WalletAddress>(this);
	FC_UEM_MudEntityIdMapping MudEntityIdMapping =UCF_GroupsStatics::GetSingletonComponent<FC_UEM_MudEntityIdMapping>(this);

	if(MudEntityIdMapping.MudEntityIdToLocalContextId.Contains(Wallet.EthWalletAddress)
		&& MudEntityIdMapping.MudEntityIdToLocalContextId[Wallet.EthWalletAddress] == PlayerComponentSet.ContextId &&
		!UCF_Statics::HasComponentForContextId_Template<FC_UEE_IsLocalPlayer>(this,PlayerComponentSet.ContextId))
	{
		UCF_Statics::SetComponentOfContextId<FC_UEE_IsLocalPlayer>(
			this,
			PlayerComponentSet.ContextId,
			FC_UEE_IsLocalPlayer());
	}
	
}


void US_UEE_UpdateLocalPlayer::OnWalletComponentSet(const FCF_ComponentSetMessageBase WalletComponentSet)
{
	const FC_UEM_WalletAddress Wallet = UCF_GroupsStatics::GetSingletonComponent<FC_UEM_WalletAddress>(this);
	FC_UEM_MudEntityIdMapping MudEntityIdMapping =UCF_GroupsStatics::GetSingletonComponent<FC_UEM_MudEntityIdMapping>(this); 
	if(UCF_GroupsStatics::DoesSingletonComponentExist<FC_UEE_IsLocalPlayer>(this))
	{
		const int32 OldLocalPlayer = UCF_GroupsStatics::GetSingletonComponentContextId<FC_UEE_IsLocalPlayer>(this);
		if(MudEntityIdMapping.MudEntityIdToLocalContextId.Contains(Wallet.EthWalletAddress) &&
			MudEntityIdMapping.MudEntityIdToLocalContextId[Wallet.EthWalletAddress] == OldLocalPlayer)
		{
			return;
		}
		UCF_Statics::RemoveComponentOfContextId<FC_UEE_IsLocalPlayer>(this,OldLocalPlayer);
	}
	if(!MudEntityIdMapping.MudEntityIdToLocalContextId.Contains(Wallet.EthWalletAddress))
	{
		const FCF_Context LocalPlayerContext = UCF_Statics::CreateNewContext(this);
		MudEntityIdMapping.MudEntityIdToLocalContextId.Add(Wallet.EthWalletAddress,LocalPlayerContext.ContextId);
		UCF_GroupsStatics::SetSingletonComponent<FC_UEM_MudEntityIdMapping>(this,MudEntityIdMapping);
	}
	UCF_Statics::SetComponentOfContextId<FC_UEE_IsLocalPlayer>(
			this,
			MudEntityIdMapping.MudEntityIdToLocalContextId[Wallet.EthWalletAddress],
			FC_UEE_IsLocalPlayer());
}
