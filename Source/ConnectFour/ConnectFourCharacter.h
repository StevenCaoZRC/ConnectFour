// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ConnectFourCharacter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCFCharacter, Log, All);
//--------
//Abberivations Used
//CF = ConnectFour
//--------


UCLASS()
class CONNECTFOUR_API AConnectFourCharacter : public ACharacter
{
	GENERATED_BODY()

	//Methods
public:
	// Sets default values for this character's properties
	AConnectFourCharacter();

	UFUNCTION()
		void OnClick();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Variables
public:	
	//Main Player Camera
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "PlayerCamera")
		class UCameraComponent* PlayerCamera;

	//Player Controller - CF = ConnectFour
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCamera")
		class APlayerController* CFController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerIndex")
		int32 PlayerIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Replicated, Category = "PlayerIndex")
		int32 CurrentPlayerIndex;
};
