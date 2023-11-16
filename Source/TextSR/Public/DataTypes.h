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
	float Precision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageType DamageType;
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