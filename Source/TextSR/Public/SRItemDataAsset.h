// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TextSRTypes.h"
#include "SRItemDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class TEXTSR_API USRItemDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> SpawnActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UStaticMesh> StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Price;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Availability;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Capacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESRLegality Legality;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<USRItemDataAsset*> Mods;
};
