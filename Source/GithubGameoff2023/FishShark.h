// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fish.h"
#include "Kismet/GameplayStatics.h"
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

	UPROPERTY(EditAnywhere)
	float Health = 50.f;

	UPROPERTY(EditAnywhere)
	float BiteDamage = 5.f;
	
	class UHealthBoat* BoatHealth;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	FTimerHandle AttackTimer;

	UPROPERTY(EditAnywhere)
	float AttackTimerRate = 2.f;

	void Attack();

	bool canAttack = false;
	FVector FishPosition;
	
	UPROPERTY(EditDefaultsOnly)
	float NearBoat = 950.f;

	void MoveToBoat(float DeltaTime);

	UFUNCTION()
	void DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* Controller, AActor* DamageCauser);
	
	void Death();
};
