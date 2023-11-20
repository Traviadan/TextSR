// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SRItemDataAsset.h"
#include "SRElectronic.generated.h"

/**
 * 
 */
UCLASS()
class TEXTSR_API USRElectronic : public USRItemDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AttributeArrangement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxPrograms;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Processing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Firewall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Stealth;
};
