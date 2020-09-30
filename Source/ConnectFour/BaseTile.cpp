// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTile.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ABaseTile::ABaseTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetReplicates(true);

	// Setting Root Component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	
	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	TileMesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	TileMesh->SetStaticMesh(StaticMeshAsset.Object);							//Sets shape to cube
	TileMesh->SetRelativeScale3D(FVector(3.0f,3.0f,1.0f));						//Adjusting size here so all tiles, have unified size. Will have to override this in 
}

// Called when the game starts or when spawned
void ABaseTile::BeginPlay()
{
	Super::BeginPlay();
	//If used without params it will use default values. SEE BaseTile.h to check default values
	Initialise();
}

void ABaseTile::Initialise(bool _CanInteract, bool _Occupied, TEnumAsByte<ETileTypes> _TileType)
{
	CanInteract = _CanInteract;
	TileType = _TileType;
	Occupied = _Occupied;
}

// Called every frame
void ABaseTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseTile::Clicked()
{
}

