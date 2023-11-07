// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Fish.generated.h"

UCLASS()
class GITHUBGAMEOFF2023_API AFish : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFish();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool toDestroy = false;
	void DestroyItself();

	
private:
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* FishMesh;

	TSubclassOf<UParticleSystem> SmokeEffect;

	FVector PlayerLocation;

	void MoveToBoat(float);

	UPROPERTY(EditDefaultsOnly)
	float MovementRate;

	void RotateFishToBoat();
	
};
	