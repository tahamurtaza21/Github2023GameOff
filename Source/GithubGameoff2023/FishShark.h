// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fish.h"
#include "FishShark.generated.h"

/**
 * 
 */
UCLASS()
class GITHUBGAMEOFF2023_API AFishShark : public AFish
{
	GENERATED_BODY()

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	AFishShark();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	void Attack();
	FVector FishPosition;
	
	UPROPERTY(EditDefaultsOnly)
	float NearBoat = 950.f;

	void MoveToBoat(float DeltaTime);
	
};
