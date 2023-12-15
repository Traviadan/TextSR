// Fill out your copyright notice in the Description page of Project Settings.


#include "TextSRAsset.h"

UTextSRAsset::UTextSRAsset() :
	AssetType(TEXT("TextSRAsset"))
{
}

FPrimaryAssetId UTextSRAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(AssetType, AssetId);
}
