// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTile.generated.h"

//==================
// The tiles can use this enum to distingush what their current state is.
// Depending on the different states, the tiles will act differently.
//==================
UENUM(BlueprintType)
enum class ETileTypes : uint8
{
	PLAYER1 = 0 UMETA(DisplayName = "Player1"),		
	PLAYER2 = 1 UMETA(DisplayName = "Player2"),
	SELECTOR = 2 UMETA(DisplayName = "Selector"),
	EMPTYTILE = 3 UMETA(DisplayName = "EmptyTile"),
};


UCLASS()
class CONNECTFOUR_API ABaseTile : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	ABaseTile();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Will be executed in Begin Play. Made virtual for potential expansion in child classes
	virtual void Initialise(bool _CanInteract = false, bool _Occupied = false);

	//Setting the shape of the tile depending on the tile type
	void SetStaticMesh(TEnumAsByte<ETileTypes> _TileType);

	//Base Mesh other tiles will use.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
		class UStaticMeshComponent* TileMesh;

	//To seperate selector tiles and play tiles
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
		bool CanInteract;

	//To seperate selector tiles and play tiles
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
		bool Occupied;

	//Each tile will have its own type specified
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
		TEnumAsByte<ETileTypes> TileType;

	//Stores mesh for the different tile forms.
	 class UStaticMesh* SelectorMesh;
	 class UStaticMesh* DefaultTileMesh;


};
