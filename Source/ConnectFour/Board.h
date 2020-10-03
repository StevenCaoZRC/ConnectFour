// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Board.generated.h"

class APlayTile;

USTRUCT(BlueprintType)
struct FBoardRowData
{
	GENERATED_BODY()
public:
	FBoardRowData() {};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Board")
	TArray<APlayTile*> PlayTileArray_Rows;

};

UCLASS()
class CONNECTFOUR_API ABoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoard();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Board")
		TArray<FBoardRowData> PlayTileArray_Columns;



};
