// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Systems/UpdateWallet/S_UEE_UpdatePlayerWallet.h"

#include "Secp256k1Helper.h"
#include "Core/Component/Messages/ComponentSet/CF_ComponentSetMessage.h"
#include "EventSystem/StaticFuntionLibrary/CF_EventStatics.h"
#include "EventSystem/Subsystems/S_CF_Event.h"
#include "Group/StaticFuntionLibrary/CF_GroupsStatics.h"
#include "Player/Components/WalletName/C_UEE_PlayerWalletName.h"
#include "Player/Systems/InitializeWallet/S_UEE_InitializePlayerWallet.h"
#include "Wallet/Wallet_Library.h"
#include "Wallet/Components/Wallet/C_UEM_LocalWallet.h"
#include "Wallet/Components/Wallet/C_UEM_WalletAddress.h"
#include "Wallet/Components/Wallet/C_UEM_WalletSettings.h"
#include "Wallet/Systems/S_UEM_Wallet_Initialize.h"
#include "WorldSettings/Systems/S_UEM_LoadWorldSettings.h"


void US_UEE_UpdatePlayerWallet::Initialize(FSubsystemCollectionBase& Collection)
{

	Super::Initialize(Collection);
	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_UEM_LoadWorldSettings::StaticClass());
	Collection.InitializeDependency(US_UEM_Wallet_Initialize::StaticClass());
	Collection.InitializeDependency(US_UEE_InitializePlayerWallet::StaticClass());
	
	

	UCF_EventStatics::AddLambdaListener<FCF_ComponentSetMessageBase,FC_UEE_PlayerWalletName>(this,
		[this](const UObject* Invoker,const FCF_ComponentSetMessageBase MovableComponentSet)
	{
		OnWalletNameComponentSet(MovableComponentSet);
	});


	
}

void US_UEE_UpdatePlayerWallet::OnWalletNameComponentSet(const FCF_ComponentSetMessageBase WalletNameComponentSet)
{
	FString WalletName = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_PlayerWalletName>(this).WalletName;
	const FC_UEM_WalletSettings WalletSettings = UCF_GroupsStatics::GetSingletonComponent<FC_UEM_WalletSettings>(this);

	TArray<uint8> WalletPrivateKey;
	if(UWallet_Library::WalletExists(WalletSettings.DefaultWalletName))
	{
		WalletPrivateKey = UWallet_Library::ReadWallet(WalletSettings.DefaultWalletName);
	}
	else
	{
		WalletPrivateKey = UWallet_Library::CreateWallet(WalletSettings.DefaultWalletName);
	}
	
	const FC_UEM_LocalWallet LocalWallet =FC_UEM_LocalWallet(WalletPrivateKey);
	if(UCF_GroupsStatics::DoesSingletonComponentExist<FC_UEM_LocalWallet>(this))
	{
		UCF_GroupsStatics::SetSingletonComponent<FC_UEM_LocalWallet>(this,LocalWallet);	
	}
	else
	{
		const FCF_Context MapVisualContext = UCF_Statics::CreateNewContext(this);
		UCF_Statics::SetComponentOfContextId<FC_UEM_LocalWallet>(this,MapVisualContext.ContextId,LocalWallet);
	}
    	
	if(WalletSettings.WalletMode == EWalletMode::Local)
	{
		const FString EthWalletAddress = USecp256k1Helper::CalcPublicAddressFromPrivateKey(WalletPrivateKey.GetData());
		if(UCF_GroupsStatics::DoesSingletonComponentExist<FC_UEM_WalletAddress>(this))
		{
			UCF_GroupsStatics::SetSingletonComponent<FC_UEM_WalletAddress>(this,FC_UEM_WalletAddress(EthWalletAddress));	
		}
		else
		{
			const FCF_Context MapVisualContext = UCF_Statics::CreateNewContext(this);
			UCF_Statics::SetComponentOfContextId<FC_UEM_WalletAddress>(this,MapVisualContext.ContextId,FC_UEM_WalletAddress(EthWalletAddress));
		}
	}
}
