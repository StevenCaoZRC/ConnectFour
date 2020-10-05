// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"
#include "PlayTile.h"
#include "ConnectFourCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
// Sets default values
ABoard::ABoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	EmptyTilesRemaining = 42;
	
	CheckDirection = 1;
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();
	PlayerReference = Cast<AConnectFourCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

bool ABoard::CheckWin(APlayTile* CurrentTile)
{
	//Once it reaches 0 this means the board is filled 
	if (EmptyTilesRemaining > 0)
	{
		EmptyTilesRemaining--;
	}
	CheckHorizontal(CurrentTile);
	CheckVertical(CurrentTile);
	CheckDownwardDiagonal(CurrentTile);
	CheckUpwardDiagonal(CurrentTile);
	if (PlayerReference != nullptr)
	{
		//Only returns true if one of the checks are successful, rest of win is handled in blueprints BP_Board
		if (PlayerReference->WinGame)
		{
			return true;
		}
	}

	return false;
}


//
//Checking rows for connect four
//
void ABoard::CheckHorizontal(APlayTile* CurrentTile)
{
	for (uint8 columns = 0; columns < PlayTileArray_Columns.Num()-3; columns++)
	{
		for (uint8 rows = 0; rows < PlayTileArray_Columns[columns].PlayTileArray_Rows.Num(); rows++)
		{
			if (PlayTileArray_Columns[columns].PlayTileArray_Rows[rows]->TileType == CurrentTile->TileType &&
				PlayTileArray_Columns[columns+1].PlayTileArray_Rows[rows]->TileType == CurrentTile->TileType &&
				PlayTileArray_Columns[columns+2].PlayTileArray_Rows[rows]->TileType == CurrentTile->TileType &&
				PlayTileArray_Columns[columns+3].PlayTileArray_Rows[rows]->TileType == CurrentTile->TileType)
			{
				if (PlayerReference == nullptr)
				{
					PlayerReference = Cast<AConnectFourCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
				}
				PlayerReference->WinGame = true;
				return;
			}
		}
	}
}

//
//Checking columns for connect four
//
void ABoard::CheckVertical(APlayTile* CurrentTile)
{
	for (uint8 columns = 0; columns < PlayTileArray_Columns.Num(); columns++)
	{
		for (uint8 rows = 0; rows < PlayTileArray_Columns[columns].PlayTileArray_Rows.Num()-3; rows++)
		{
			if (PlayTileArray_Columns[columns].PlayTileArray_Rows[rows]->TileType == CurrentTile->TileType &&
				PlayTileArray_Columns[columns].PlayTileArray_Rows[rows+1]->TileType == CurrentTile->TileType &&
				PlayTileArray_Columns[columns].PlayTileArray_Rows[rows+2]->TileType == CurrentTile->TileType &&
				PlayTileArray_Columns[columns].PlayTileArray_Rows[rows+3]->TileType == CurrentTile->TileType)
			{
				if (PlayerReference == nullptr)
				{
					PlayerReference = Cast<AConnectFourCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
				}
				PlayerReference->WinGame = true;
				return;
			}
		}
	}
}
//
//Checks from the top left corner to the bottom right diagonal direction
//
void ABoard::CheckDownwardDiagonal(APlayTile* CurrentTile)
{
	for (uint8 columns = 0; columns < PlayTileArray_Columns.Num()-3; columns++)
	{
		for (uint8 rows = 0; rows < PlayTileArray_Columns[columns].PlayTileArray_Rows.Num()-3; rows++)
		{
			if (PlayTileArray_Columns[columns].PlayTileArray_Rows[rows]->TileType == CurrentTile->TileType &&
				PlayTileArray_Columns[columns+1].PlayTileArray_Rows[rows + 1]->TileType == CurrentTile->TileType &&
				PlayTileArray_Columns[columns+2].PlayTileArray_Rows[rows + 2]->TileType == CurrentTile->TileType &&
				PlayTileArray_Columns[columns+3].PlayTileArray_Rows[rows + 3]->TileType == CurrentTile->TileType)
			{
				if (PlayerReference == nullptr)
				{
					PlayerReference = Cast<AConnectFourCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
				}
				PlayerReference->WinGame = true;
				return;
			}
		}
	}
}

//
//Checks from the bottom left corner to the top right diagonal direction
//
void ABoard::CheckUpwardDiagonal(APlayTile* CurrentTile)
{
	for (uint8 columns = 0; columns < PlayTileArray_Columns.Num()-3; columns++)
	{
		for (uint8 rows = PlayTileArray_Columns[columns].PlayTileArray_Rows.Num()-1; rows > 3; rows--)
		{
			if (PlayTileArray_Columns[columns].PlayTileArray_Rows[rows]->TileType == CurrentTile->TileType &&
				PlayTileArray_Columns[columns + 1].PlayTileArray_Rows[rows - 1]->TileType == CurrentTile->TileType &&
				PlayTileArray_Columns[columns + 2].PlayTileArray_Rows[rows - 2]->TileType == CurrentTile->TileType &&
				PlayTileArray_Columns[columns + 3].PlayTileArray_Rows[rows - 3]->TileType == CurrentTile->TileType)
			{
				if (PlayerReference == nullptr)
				{
					PlayerReference = Cast<AConnectFourCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
				}
				PlayerReference->WinGame = true;
				return;
			}
		}
	}
}



// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

