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

UENUM(BlueprintType)
enum class ESRItemCondition : uint8
{
	ESRIC_New UMETA(DisplayName = "Neu"),
	ESRIC_Used UMETA(DisplayName = "Gebraucht"),
	ESRIC_Defective UMETA(DisplayName = "Defekt"),
	ESRIC_Destroyed UMETA(DisplayName = "Zerstört"),

	ESRIC_MAX UMETA(DisplayName = "DefaultMAX")
};

UENUM(BlueprintType)
enum class ESRItemVisibility : uint8
{
	ESRIV_Normal UMETA(DisplayName = "Normal"),
	ESRIV_Hidden UMETA(DisplayName = "Versteckt"),
	ESRIV_Invisible UMETA(DisplayName = "Unsichtbar"),

	ESRIC_MAX UMETA(DisplayName = "DefaultMAX")
};

UENUM(BlueprintType)
enum class ESRLegality : uint8
{
	ESRL_Legal UMETA(DisplayName = "Legal"),
	ESRL_Restricted UMETA(DisplayName = "Eingeschränkt"),
	ESRL_Forbidden UMETA(DisplayName = "Verboten"),

	ESRIC_MAX UMETA(DisplayName = "DefaultMAX")
};

USTRUCT(BlueprintType)
struct FSRItemTable : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

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
	FString Mods;
};

USTRUCT(BlueprintType)
struct FSRElectronicsTable : public FSRItemTable
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
	UPrimaryDataAsset* ItemAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UPrimaryDataAsset*> ModifierAssets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESRItemCondition ItemCondition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESRItemVisibility ItemVisibility;
};

/**
 * 
 */
UCLASS()
class TEXTSR_API UTextSRTypes : public UObject
{
	GENERATED_BODY()
	
};
