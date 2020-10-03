// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTile.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ABaseTile::ABaseTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Allows networking features to be used and replicates the tile
	SetReplicates(true);

	// Setting Root Component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	// Setting up Default Mesh types
	SelectorMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid")).Object;
	DefaultTileMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder")).Object;

	// Tile mesh is created and set to default square mesh so it can be viewed in editor
	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	TileMesh->SetupAttachment(RootComponent);
	TileMesh->SetStaticMesh(DefaultTileMesh);
}

// Called when the game starts or when spawned
void ABaseTile::BeginPlay()
{
	Super::BeginPlay();
	SetStaticMesh(TileType);
	Initialise();
}

void ABaseTile::Initialise(bool _CanInteract, bool _Occupied)
{
	CanInteract = _CanInteract;
	Occupied = _Occupied;
}

void ABaseTile::SetStaticMesh(ETileTypes _TileType)
{
	if (_TileType == ETileTypes::SELECTOR)
	{
		TileMesh->SetStaticMesh(SelectorMesh);
		TileMesh->SetRelativeScale3D(FVector(3.0f));
		RootComponent->SetRelativeRotation(FQuat(FVector(0.0f, 180.0f, 0.0f ), 1.0f));			//Rotates pyramid upside down so its point at the board
	}
	else
	{
		TileMesh->SetStaticMesh(DefaultTileMesh);												//Sets shape to cube if the tile is anything besides a selector tile
		TileMesh->SetRelativeScale3D(FVector(3.0f));											//Adjusting size here so all tiles, have unified size. Will have to override this in 
		

	}
}

// Called every frame
void ABaseTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

