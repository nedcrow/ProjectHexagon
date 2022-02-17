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
	for (auto tile : TileStructs) ISM->RemoveInstance(0);
	TileStructs.Empty();

	/* Create */
	for (int y = 0; y < SizeY; y++) {
		for (int x = 0; x < SizeX; x++) {
			float additionalY = (x % 2 != 0) ? unitY * 0.5f : 0.f;
			float offsetX = Offset * x;
			float offsetY = Offset * y;

			FTileStruct tile;
			tile.Location = FVector((x * unitX) * Unit + offsetX, (y * unitY + additionalY) * Unit + offsetY, 0.f);
			tile.InUseCameraIndex = DefaultInUseCameraIndex;
			TileStructs.Add(tile);
		}
	}

	for (FTileStruct tile : TileStructs) {
		ISM->AddInstance(FTransform(
			FRotator::ZeroRotator,
			tile.Location,
			FVector::OneVector
		));
	}	
}

