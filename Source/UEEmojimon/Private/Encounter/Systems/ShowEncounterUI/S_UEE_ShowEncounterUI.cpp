// Fill out your copyright notice in the Description page of Project Settings.


#include "Encounter/Systems/ShowEncounterUI/S_UEE_ShowEncounterUI.h"
#include "Blueprint/UserWidget.h"
#include "Core/Component/Messages/ComponentSet/CF_ComponentSetMessage.h"
#include "Core/StaticFunctionLibrary/CF_Statics.h"
#include "Encounter/Components/EncounterSettings/C_UEE_EncounterSettings.h"
#include "Encounter/Components/EncounterUI/C_UEE_EncounterUI.h"
#include "Encounter/Systems/LoadEncounterSettings/S_UEE_LoadEncounterSettings.h"
#include "Encounter/UI/W_UEE_Encounter.h"
#include "EventSystem/StaticFuntionLibrary/CF_EventStatics.h"
#include "EventSystem/Subsystems/S_CF_Event.h"
#include "Group/StaticFuntionLibrary/CF_GroupsStatics.h"
#include "Mud/Components/Encounter/C_UEE_Encounter.h"
#include "Player/Components/IsLocalPlayer/C_UEE_IsLocalPlayer.h"

void US_UEE_ShowEncounterUI::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_CF_Event::StaticClass());
	Collection.InitializeDependency(US_UEE_LoadEncounterSettings::StaticClass());

	

	UCF_EventStatics::AddLambdaListener<FCF_ComponentSetMessageBase,FC_UEE_Encounter>(this,
		[this](const UObject* Invoker,const FCF_ComponentSetMessageBase EncounterComponentSet)
	{
		OnEncounterComponentAdded(EncounterComponentSet);
	});

}

void US_UEE_ShowEncounterUI::OnEncounterComponentAdded(const FCF_ComponentSetMessageBase EncounterComponentSet)
{
	if(!UCF_Statics::HasComponentForContextId_Template<FC_UEE_IsLocalPlayer>(this,EncounterComponentSet.ContextId))
		return;


	const FC_UEE_EncounterSettings EncounterSettings = UCF_GroupsStatics::GetSingletonComponent<FC_UEE_EncounterSettings>(this);

	
	const auto PlayerController = UGameplayStatics::GetPlayerController(this,0);
	const TSubclassOf<UUserWidget> EncounterClass = EncounterSettings.EncounterUIClass;
	const auto EncounterWidget = CreateWidget(PlayerController,EncounterClass);
	EncounterWidget->AddToViewport();

	//Cast<UW_CO_EncounterUIScreen>(EncounterWidget)->OnEncounterStarted(Encounter_Started);
	const FCF_Context EncounterUIContext = UCF_Statics::CreateNewContext(this);
	const FC_UEE_EncounterUI EncounterScreenComponent = FC_UEE_EncounterUI(Cast<UW_UEE_Encounter>(EncounterWidget));
	UCF_Statics::SetComponentOfContextId<FC_UEE_EncounterUI>(this,EncounterUIContext.ContextId,EncounterScreenComponent);
}
