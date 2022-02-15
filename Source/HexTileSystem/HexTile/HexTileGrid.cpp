// Fill out your copyright notice in the Description page of Project Settings.


#include "HexTileGrid.h"

#include "Components/SphereComponent.h"
#include "Components/InstancedStaticMeshComponent.h"

// Sets default values
AHexTileGrid::AHexTileGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	RootComponent = Sphere;

	ISM = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ISM"));
	ISM->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHexTileGrid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHexTileGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHexTileGrid::PostRegisterAllComponents()
{
	Super::PreRegisterAllComponents();
	SetTileMatrix();
}

void AHexTileGrid::SetTileMatrix()
{
	float centralDegree = 60;
	float centralRadian = FMath::Sin(2 * PI * (centralDegree / 360));
	float oneSide = centralRadian * TileScale;
	float unitX = 0.75f * TileScale;
	float unitY = oneSide;

	/* Clear */
	for (FVector location : TileMatrix) ISM->RemoveInstance(0);
	TileMatrix.Empty();

	/* Create */
	for (int y = 0; y < SizeY; y++) {
		for (int x = 0; x < SizeX; x++) {
			float additionalY = (x % 2 != 0) ? unitY * 0.5f : 0;
			TileMatrix.Add(FVector((x * unitX) * Unit, (y * unitY + additionalY) * Unit, 0.f));

		}
	}

	for (FVector location : TileMatrix) {
		ISM->AddInstance(FTransform(
			FRotator::ZeroRotator,
			location,
			FVector::OneVector
		));
	}	
}

