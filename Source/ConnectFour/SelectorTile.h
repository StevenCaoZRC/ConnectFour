// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTile.h"
#include "SelectorTile.generated.h"

/**
 * 
 */
UCLASS()
class CONNECTFOUR_API ASelectorTile : public ABaseTile
{
	GENERATED_BODY()
	
public:
	ASelectorTile();

protected:

	virtual void BeginPlay() override;
};
