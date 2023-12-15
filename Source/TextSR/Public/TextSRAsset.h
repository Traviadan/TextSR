// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TextSRAsset.generated.h"

/**
 * 
 */
UCLASS()
class TEXTSR_API UTextSRAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UTextSRAsset();

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FName AssetType;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FName AssetId;
};
