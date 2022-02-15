// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTileGrid.generated.h"

UCLASS()
class HEXTILESYSTEM_API AHexTileGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	AHexTileGrid();


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class USphereComponent* Sphere;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UInstancedStaticMeshComponent* ISM;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void PostRegisterAllComponents();

/* Matrix */
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (Tooltip = "Centimeter"))
	int Unit = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int SizeX = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int SizeY = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TileScale = 1.f;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<FVector> TileMatrix;
	
	void SetTileMatrix();

};
