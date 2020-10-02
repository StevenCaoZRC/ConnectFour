// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTile.h"
#include "PlayTile.generated.h"

/**
 * PlayTiles will be the main pieces on the board.
 */
UCLASS()
class CONNECTFOUR_API APlayTile : public ABaseTile
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlayTile();
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:

	virtual void BeginPlay() override;
};
