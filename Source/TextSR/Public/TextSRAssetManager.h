// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "TextSRAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class TEXTSR_API UTextSRAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:

	static UTextSRAssetManager& Get();

	/** Starts initial load, gets called from InitializeObjectReferences */
	virtual void StartInitialLoading() override;
};
