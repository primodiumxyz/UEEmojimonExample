// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Systems/LoadPlayerVisual/S_UEE_LoadPlayerVisualSettings.h"

#include "Core/Subsystems/S_CF_Core.h"
#include "Group/SubSystems/S_CF_Groups.h"
#include "Player/Components/PlayerVisualSettings/C_UEE_PlayerVisualSettings.h"
#include "Player/Settings/DS_UEE_PlayerVisual.h"


void US_UEE_LoadPlayerVisualSettings::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Collection.InitializeDependency(US_CF_Core::StaticClass());
	Collection.InitializeDependency(US_CF_Groups::StaticClass());
	Collection.InitializeDependency(US_CF_Event::StaticClass());

	const UDS_UEE_PlayerVisual* PlayerVisualSettings = GetDefault<UDS_UEE_PlayerVisual>();
	PlayerVisual = PlayerVisualSettings->PlayerVisual.LoadSynchronous();
	NonLocalPlayerVisual = PlayerVisualSettings->NonLocalPlayerVisual.LoadSynchronous();
	
	const FCF_Context PlayerVisualSettingsContext = UCF_Statics::CreateNewContext(this);
	const FC_UEE_PlayerVisualSettings PlayerVisualSettingsComponent = FC_UEE_PlayerVisualSettings(PlayerVisual, NonLocalPlayerVisual);
	UCF_Statics::SetComponentOfContextId<FC_UEE_PlayerVisualSettings>(this,PlayerVisualSettingsContext.ContextId,PlayerVisualSettingsComponent);
}
