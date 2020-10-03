// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayTile.h"
#include "ConnectFourCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Net/UnrealNetwork.h"

APlayTile::APlayTile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OrangeMaterial = CreateDefaultSubobject<UMaterialInstance>(TEXT("Player Orange Material"));
	BlueMaterial = CreateDefaultSubobject<UMaterialInstance>(TEXT("Player Blue Material"));
	
	TileType = ETileTypes::EMPTYTILE;
	Player = Cast<AConnectFourCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	SetReplicates(true);
}

void APlayTile::BeginPlay()
{
	Super::BeginPlay();
}

void APlayTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayTile::ServerChangeColour_Implementation()
{
	if (Player->CurrentPlayerIndex == 0)
	{
		//Server's turn
		TileMesh->SetMaterial(0, OrangeMaterial);
		Occupied = true;
		Player->CurrentPlayerIndex = 1;
	}
	else
	{
		//Client's turn
		TileMesh->SetMaterial(0, BlueMaterial);
		Occupied = true;
		Player->CurrentPlayerIndex = 0;
	}
}

void APlayTile::ChangeColour()
{
	if (HasAuthority())
	{
		ServerChangeColour();
	}
}



