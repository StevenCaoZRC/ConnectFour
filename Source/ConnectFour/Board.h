// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTile.h"
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

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Player")
		class AConnectFourCharacter* PlayerReference;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int CheckDirection;
	//Check win
	UFUNCTION(BlueprintCallable, Category = "Board")
	bool CheckWin(APlayTile* CurrentTile);
	void CheckHorizontal(APlayTile* CurrentTile);
	void CheckVertical(APlayTile* CurrentTile);
	void CheckDownwardDiagonal(APlayTile* CurrentTile);
	void CheckUpwardDiagonal(APlayTile* CurrentTile);
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Board")
		TArray<FBoardRowData> PlayTileArray_Columns;
	//Since number maximum is 41, only requires uint8 0 - 255
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Board")
		uint8 EmptyTilesRemaining;


	//Since number maximum is 4, only requires uint8 0 - 255
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Board")
		uint8 CheckCounter; //Only need to check 4 in each direction
};
