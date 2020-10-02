// Fill out your copyright notice in the Description page of Project Settings.


#include "ConnectFourCharacter.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "Net/UnrealNetwork.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(LogCFCharacter);

//MACRO for fast on screen debug text
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Orange, text);

// Sets default values
AConnectFourCharacter::AConnectFourCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set Replicatiable
	SetReplicates(true);

	// Setting Root Component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	// Setting Static Camera Component
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(RootComponent);
	PlayerCamera->bLockToHmd = true;
	PlayerCamera->bUsePawnControlRotation = false;

	CFController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	//Cast Successful
	if (CFController)
	{
		CFController->bShowMouseCursor = true;
	}
}

// Called when the game starts or when spawned
void AConnectFourCharacter::BeginPlay()
{
	Super::BeginPlay();
	//Differeniating the different players 
	if (HasAuthority())
	{
		PlayerIndex = 0;
	}
	else
	{
		PlayerIndex = 1;
	}
	//Server going first
	CurrentPlayerIndex = 0;
}

void AConnectFourCharacter::OnClick()
{
	//When player left clicks mouse, could also be done in blueprints
}

void AConnectFourCharacter::OnRep_CurrentPlayerIndex()
{
	//When it is end of turn
}

void AConnectFourCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	//List of variables that are replicated
	DOREPLIFETIME(AConnectFourCharacter, CurrentPlayerIndex);
}

// Called every frame
void AConnectFourCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AConnectFourCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Bind Trigger Click to OnClick method

	PlayerInputComponent->BindAction("TriggerClick", IE_Pressed, this, &AConnectFourCharacter::OnClick);
}

