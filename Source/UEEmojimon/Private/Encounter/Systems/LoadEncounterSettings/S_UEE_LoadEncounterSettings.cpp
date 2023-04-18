// Fill out your copyright notice in the Description page of Project Settings.


#include "Encounter/Systems/LoadEncounterSettings/S_UEE_LoadEncounterSettings.h"

#include "Core/Subsystems/S_CF_Core.h"
#include "Encounter/Components/EncounterSettings/C_UEE_EncounterSettings.h"
#include "Encounter/Settings/DS_UEE_Encounter.h"
#include "Group/SubSystems/S_CF_Groups.h"

class UDS_UEE_Encounter;

void US_UEE_LoadEncounterSettings::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Collection.InitializeDependency(US_CF_Core::StaticClass());
	Collection.InitializeDependency(US_CF_Groups::StaticClass());
	Collection.InitializeDependency(US_CF_Event::StaticClass());

	const UDS_UEE_Encounter* EncounterSettings = GetDefault<UDS_UEE_Encounter>();
	EncounterUIClass = EncounterSettings->EncounterUI.LoadSynchronous();
	
	
	const FCF_Context EncounterSettingsContext = UCF_Statics::CreateNewContext(this);
	const FC_UEE_EncounterSettings EncounterSettingsComponent = FC_UEE_EncounterSettings(EncounterUIClass);
	UCF_Statics::SetComponentOfContextId<FC_UEE_EncounterSettings>(this,EncounterSettingsContext.ContextId,EncounterSettingsComponent);
}
