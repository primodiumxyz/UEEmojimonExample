// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Systems/JoinGame/MS_UEE_JoinGame.h"

#include "Core/StaticFunctionLibrary/CF_Statics.h"
#include "Core/Subsystems/S_CF_Core.h"
#include "Encoding/Components/SystemIdToEncoderDecoder/C_UEM_MudSystemEncoderDecoders.h"
#include "Encoding/Systems/S_UEM_InitializeSystemEncoderDecoders.h"
#include "Group/StaticFuntionLibrary/CF_GroupsStatics.h"
#include "Mud/Systems/JoinGame/Messages/M_UEE_JoinGame_Execute.h"

FString UMS_UEE_JoinGame::GetSystemId()
{
	return "system.JoinGame";
}

bool UMS_UEE_JoinGame::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void UMS_UEE_JoinGame::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Collection.InitializeDependency(US_CF_Core::StaticClass());
	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_UEM_InitializeSystemEncoderDecoders::StaticClass());
	

	UCF_EventStatics::AddLambdaListener<FM_UEE_JoinGame_Execute>(this,
	[this](const UObject* Invoker,const FM_UEE_JoinGame_Execute EstimateGasRequest)
	{
		OnJoinGameExecute(EstimateGasRequest);
	});

	

}

void UMS_UEE_JoinGame::OnJoinGameExecute(FM_UEE_JoinGame_Execute JoinGame_Execute)
{
	FC_UEM_MudSystemEncoderDecoders MudSystemEncoderDecoders = UCF_GroupsStatics::GetSingletonComponent<FC_UEM_MudSystemEncoderDecoders>(this);


	
	FString SystemIdHex = GetHexSystemId();
	if(!MudSystemEncoderDecoders.SystemIdToEncoderDecoder.Contains(SystemIdHex))
	{
		throw;
	}
	USED_UEM_Base* JoinGameEncoderDecoder = MudSystemEncoderDecoders.SystemIdToEncoderDecoder[SystemIdHex];
	
	
	FInstancedStruct JoinGameInstancedStruct;
	JoinGameInstancedStruct.InitializeAs<FM_UEE_JoinGame_Execute>(JoinGame_Execute);
	
	const FString EncodedArguments = JoinGameEncoderDecoder->GetEncodedArguments(JoinGameInstancedStruct);
	const TArray<FString> Arguments = JoinGameEncoderDecoder->GetStringArguments(JoinGameInstancedStruct);
	ExecuteSystemCall(JoinGameEncoderDecoder->ContractAddress,JoinGameEncoderDecoder->ComponentContractAbi,"executeTyped",Arguments,EncodedArguments);
	
}
