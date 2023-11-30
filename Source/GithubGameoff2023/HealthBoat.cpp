// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBoat.h"
#include "Boat.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthBoat::UHealthBoat()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthBoat::BeginPlay()
{
	Super::BeginPlay();

	Boat = Cast<ABoat>(GetOwner());
}

void UHealthBoat::Death()
{
	//UE_LOG(LogTemp,Display, TEXT("Dead"));
	APawn* Player = UGameplayStatics::GetPlayerPawn(this, 0);
	if(Player != nullptr)
	{
		Player->DetachFromControllerPendingDestroy();	
	}
	else
	{
		UE_LOG(LogTemp,Display, TEXT("Player Pawn not Found"));
	}
}

