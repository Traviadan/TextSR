// Fill out your copyright notice in the Description page of Project Settings.


#include "TextSRAssetManager.h"

UTextSRAssetManager& UTextSRAssetManager::Get()
{
	UTextSRAssetManager* Singleton = Cast<UTextSRAssetManager>(GEngine->AssetManager);

	if (Singleton)
	{
		return *Singleton;
	}
	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("Invalid AssetManager in DefaultEngine.ini, must be RunnersAssetManager!"));
		return *NewObject<UTextSRAssetManager>();	 // never calls this
	}
}

void UTextSRAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
}
