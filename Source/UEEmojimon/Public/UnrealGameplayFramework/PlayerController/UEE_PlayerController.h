// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mud/Systems/JoinGame/Messages/M_UEE_JoinGame_Execute.h"
#include "Mud/Systems/Move/Messages/M_UEE_Move_Execute.h"
#include "UEE_PlayerController.generated.h"





UCLASS(Blueprintable, BlueprintType)
class UEEMOJIMON_API AUEE_PlayerController : public APlayerController
{
	GENERATED_BODY()



	
public:
	// Sets default values for this actor's properties
	AUEE_PlayerController();

protected:


public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MudPlayerContextID = 81;
	


	UFUNCTION(BlueprintCallable)
	void TryMove(FM_UEE_Move_Execute Move_Execute);

	UFUNCTION(BlueprintCallable)
	void TrySelectStartPosition(FM_UEE_JoinGame_Execute JoinGame_Execute);


	UFUNCTION(BlueprintCallable,Exec)
	void UpdateWallet(FString WalletName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectStartPosition();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectMovePosition();
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectEncounterStrategy();

	virtual void Tick(float DeltaSeconds) override;
};
