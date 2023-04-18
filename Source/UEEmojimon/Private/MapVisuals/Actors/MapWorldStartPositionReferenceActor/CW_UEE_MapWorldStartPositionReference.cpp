// Fill out your copyright notice in the Description page of Project Settings.


#include "MapVisuals/Actors/MapWorldStartPositionReferenceActor/CW_UEE_MapWorldStartPositionReference.h"

#include "Core/StaticFunctionLibrary/CF_Statics.h"
#include "MapVisuals/Components/MapStartWorldPosition/C_UEE_MapStartPositionReferenceActor.h"


void ACW_UEE_MapWorldStartPositionReference::BeginPlay()
{
	Super::BeginPlay();
	UCF_Statics::SetComponentOfContextId<FC_UEE_MapStartPositionReferenceActor>(
		this,ContextId,FC_UEE_MapStartPositionReferenceActor(this));
}
