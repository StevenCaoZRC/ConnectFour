// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayTile.h"

APlayTile::APlayTile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TileType = ETileTypes::EMPTYTILE;

}

void APlayTile::BeginPlay()
{
	Super::BeginPlay();
}

void APlayTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


