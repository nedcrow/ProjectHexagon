// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "HexTileVolume.generated.h"

/**
 * 
 */
UCLASS()
class HEXTILESYSTEM_API AHexTileVolume : public AVolume
{
	GENERATED_BODY()
	
public:
	AHexTileVolume();

	//Begin UObject Interface
#if WITH_EDITOR
	virtual void PostEditImport() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR
	//End UObject Interface

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ScaleUnit = 1.0f;
};
