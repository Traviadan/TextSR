// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "TextSRTypes.generated.h"

UENUM(BlueprintType)
enum class ESRDamageType : uint8
{
	ESRDT_Physical UMETA(DisplayName = "Physical Damage"),
	ESRDT_Stun UMETA(DisplayName = "Stun Damage"),

	ESRDT_MAX UMETA(DisplayName = "DefaultMAX")
};

UENUM(BlueprintType)
enum class ESRWeaponType : uint8
{
	ESRWT_CloseCombatBlade UMETA(DisplayName = "Klingenwaffen"),
	ESRWT_CloseCombatBlunt UMETA(DisplayName = "Knüppel"),
	ESRWT_CloseCombatOther UMETA(DisplayName = "Andere Nahkampfwaffen"),

	ESRWT_MAX UMETA(DisplayName = "DefaultMAX")
};

USTRUCT(BlueprintType)
struct FSRItemTable : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Price;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Availability;
};

USTRUCT(BlueprintType)
struct FSRWeaponTable : public FSRItemTable
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

USTRUCT(BlueprintType)
struct FSRCloseCombatWeaponTable : public FSRWeaponTable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Reach;
};

USTRUCT(BlueprintType)
struct FSRRangedCombatWeaponTable : public FSRWeaponTable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FireModes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RecoilCompensation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Ammunition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LoadingMechanism;
};

USTRUCT(BlueprintType)
struct FSRItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* ItemTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName RowName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UDataTable*> ModifierTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> ModifierRowName;
};

/**
 * 
 */
UCLASS()
class TEXTSR_API UTextSRTypes : public UObject
{
	GENERATED_BODY()
	
};
