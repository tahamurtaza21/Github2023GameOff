// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthBoat.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GITHUBGAMEOFF2023_API UHealthBoat : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthBoat();

	UPROPERTY(EditAnywhere)
	float Health = 100.f;

	void Death();
	
	//UFUNCTION(BlueprintCallable)
	//void SetBoatReference(class );

protected:
	// Called when the game starts	
	virtual void BeginPlay() override;

private:
	class ABoat* Boat;
};
