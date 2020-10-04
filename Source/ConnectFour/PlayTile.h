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
	
	UFUNCTION(BlueprintCallable, Category = "PlayTile")
	void SetAlreadyChecked(bool Checked);

	bool GetAlreadyChecked();

	UFUNCTION(NetMulticast, reliable)
	virtual void ServerChangeColour();
	UFUNCTION(BlueprintCallable, Category = "PlayTile")
	void ChangeColour();
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Player")
	class AConnectFourCharacter* Player;

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class UMaterialInstance* OrangeMaterial;
	UPROPERTY(EditAnywhere)
		class UMaterialInstance* BlueMaterial;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
		bool AlreadyChecked;
};
