// Fill out your copyright notice in the Description page of Project Settings.


#include "MapVisuals/Systems/LoadMapVisualSettings/S_UEE_LoadMapVisualSettings.h"

#include "Core/Context/CF_Context.h"
#include "Core/StaticFunctionLibrary/CF_Statics.h"
#include "Group/SubSystems/S_CF_Groups.h"
#include "MapVisuals/Components/MapVisualSettings/C_UEE_MapVisualSettings.h"
#include "MapVisuals/Settings/DS_UEE_MapVisualSettings.h"


void US_UEE_LoadMapVisualSettings::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Collection.InitializeDependency(US_CF_Core::StaticClass());
	Collection.InitializeDependency(US_CF_Groups::StaticClass());
	Collection.InitializeDependency(US_CF_Event::StaticClass());

	const UDS_UEE_MapVisualSettings* MapVisualSettings = GetDefault<UDS_UEE_MapVisualSettings>();
	for (auto TerrainVisual : MapVisualSettings->TerrainVisuals)
	{
		TerrainVisuals.Add(TerrainVisual.Key,TerrainVisual.Value.LoadSynchronous());
	}

	const FCF_Context MapVisualSettingsContext = UCF_Statics::CreateNewContext(this);
	const FC_UEE_MapVisualSettings MapVisualSettingsComponent = FC_UEE_MapVisualSettings(TerrainVisuals);
	UCF_Statics::SetComponentOfContextId<FC_UEE_MapVisualSettings>(this,MapVisualSettingsContext.ContextId,MapVisualSettingsComponent);
}
