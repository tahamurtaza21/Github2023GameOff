// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fish.h"
#include "FishScales.generated.h"

/**
 * 
 */
UCLASS()
class GITHUBGAMEOFF2023_API AFishScales : public AFish
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	AFishScales();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void MoveToBoat(float);
	FVector FishLocation;
};
