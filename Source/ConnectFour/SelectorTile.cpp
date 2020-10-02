// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectorTile.h"


ASelectorTile::ASelectorTile()
{
	//Establish the Tile type for Selector tiles. This will determine its mesh
	TileType = ETileTypes::SELECTOR;
}

void ASelectorTile::BeginPlay()
{
	Super::BeginPlay();
}
