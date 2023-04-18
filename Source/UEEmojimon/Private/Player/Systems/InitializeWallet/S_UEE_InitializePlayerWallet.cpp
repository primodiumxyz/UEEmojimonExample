// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Systems/InitializeWallet/S_UEE_InitializePlayerWallet.h"
#include "EventSystem/Subsystems/S_CF_Event.h"
#include "Group/StaticFuntionLibrary/CF_GroupsStatics.h"
#include "Player/Components/WalletName/C_UEE_PlayerWalletName.h"
#include "Wallet/Wallet_Library.h"
#include "Wallet/Components/Wallet/C_UEM_WalletAddress.h"
#include "Wallet/Components/Wallet/C_UEM_WalletSettings.h"
#include "Wallet/Systems/S_UEM_LoadWalletSettings.h"
#include "Wallet/Systems/S_UEM_Wallet_Initialize.h"
#include "WorldSettings/Components/C_UEM_WorldSettings.h"
#include "WorldSettings/Systems/S_UEM_LoadWorldSettings.h"

void US_UEE_InitializePlayerWallet::Initialize(FSubsystemCollectionBase& Collection)
{

	Super::Initialize(Collection);
	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_UEM_LoadWalletSettings::StaticClass());
	Collection.InitializeDependency(US_UEM_Wallet_Initialize::StaticClass());


	const FCF_Context PlayerWalletContext = UCF_Statics::CreateNewContext(this);
	const FString WalletName = UCF_GroupsStatics::GetSingletonComponent<FC_UEM_WalletSettings>(this).DefaultWalletName;
	UCF_Statics::SetComponentOfContextId<FC_UEE_PlayerWalletName>(this,PlayerWalletContext.ContextId,FC_UEE_PlayerWalletName(WalletName));
	
}
