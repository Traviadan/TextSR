#pragma once

#include "Engine/DataTable.h"
#include "DataTypes.generated.h"

UENUM(BlueprintType)
enum class EDamageType : uint8
{
	EDT_Physical UMETA(DisplayName = "Physical Damage"),
	EDT_Stun UMETA(DisplayName = "Stun Damage"),

	EDT_MAX UMETA(DisplayName = "DefaultMAX")
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	EWT_CloseCombatBlade UMETA(DisplayName = "Klingenwaffen"),
	EWT_CloseCombatBlunt UMETA(DisplayName = "Knüppel"),
	EWT_CloseCombatOther UMETA(DisplayName = "Andere Nahkampfwaffen"),

	EWT_MAX UMETA(DisplayName = "DefaultMAX")
};

USTRUCT(BlueprintType)
struct FItemTable : public FTableRowBase
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
struct FWeaponTable : public FItemTable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Precision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageType DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Penetration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWeaponType WeaponType;
};

USTRUCT(BlueprintType)
struct FCloseCombatWeaponTable : public FWeaponTable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Reach;
};

USTRUCT(BlueprintType)
struct FRangedCombatWeaponTable : public FWeaponTable
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
struct FItem
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