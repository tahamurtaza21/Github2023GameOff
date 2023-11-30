// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectileScale.h"
#include "Components/ActorComponent.h"
#include "Shoot.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GITHUBGAMEOFF2023_API UShoot : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShoot();

	UPROPERTY(BlueprintReadOnly)
	int AmountOfTimesToShoot = 0;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void ShootScales();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AProjectileScale> Projectiles;
	
	int ProjectilesCount = 6;

	class UGrab* Grabber;

	FVector SpawnLocation;
	FRotator SpawnRotation;
	
};
