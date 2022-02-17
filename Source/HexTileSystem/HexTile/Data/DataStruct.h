// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "DataStruct.generated.h"

USTRUCT(BlueprintType)
struct FPointRowStruct : public FTableRowBase {
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector Location;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FRotator Rotation;
};


/**
 * 
 */
UCLASS()
class HEXTILESYSTEM_API UDataStruct : public UObject
{
	GENERATED_BODY()
	
};
