// Fill out your copyright notice in the Description page of Project Settings.


#include "Mud/Systems/Move/MS_UEE_Move.h"

#include "Core/Subsystems/S_CF_Core.h"
#include "Encoding/Components/SystemIdToEncoderDecoder/C_UEM_MudSystemEncoderDecoders.h"
#include "Encoding/Systems/S_UEM_InitializeSystemEncoderDecoders.h"
#include "Group/StaticFuntionLibrary/CF_GroupsStatics.h"
#include "Mud/Systems/Move/Messages/M_UEE_Move_Execute.h"


FString UMS_UEE_Move::GetSystemId()
{
	return "system.Move";
}

bool UMS_UEE_Move::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void UMS_UEE_Move::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Collection.InitializeDependency(US_CF_Core::StaticClass());
	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_UEM_InitializeSystemEncoderDecoders::StaticClass());
	

	UCF_EventStatics::AddLambdaListener<FM_UEE_Move_Execute>(this,
	[this](const UObject* Invoker,FM_UEE_Move_Execute Move_Execute)
	{
		OnMoveExecute(Move_Execute);
	});

	

}

void UMS_UEE_Move::OnMoveExecute(FM_UEE_Move_Execute Move_Execute)
{
	FC_UEM_MudSystemEncoderDecoders MudSystemEncoderDecoders = UCF_GroupsStatics::GetSingletonComponent<FC_UEM_MudSystemEncoderDecoders>(this);

	FString SystemIdHex = GetHexSystemId();
	if(!MudSystemEncoderDecoders.SystemIdToEncoderDecoder.Contains(SystemIdHex))
	{
		throw;
	}
	FInstancedStruct MoveInstancedStruct;
	MoveInstancedStruct.InitializeAs<FM_UEE_Move_Execute>(Move_Execute);
	USED_UEM_Base* MoveEncoderDecoder = MudSystemEncoderDecoders.SystemIdToEncoderDecoder[SystemIdHex];
	const FString EncodedArguments = MoveEncoderDecoder->GetEncodedArguments(MoveInstancedStruct);
	const TArray<FString> Arguments = MoveEncoderDecoder->GetStringArguments(MoveInstancedStruct);
	ExecuteSystemCall(MoveEncoderDecoder->ContractAddress,MoveEncoderDecoder->ComponentContractAbi,"executeTyped",Arguments,EncodedArguments);
	
}
