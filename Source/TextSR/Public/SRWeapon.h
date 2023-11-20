// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SRItemDataAsset.h"
#include "SRWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TEXTSR_API USRWeapon : public USRItemDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Precision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESRDamageType DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Penetration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESRWeaponType WeaponType;
};
