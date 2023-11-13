// Fill out your copyright notice in the Description page of Project Settings.


#include "FishScales.h"

AFishScales::AFishScales()
{
	PrimaryActorTick.bCanEverTick = true;
}
void AFishScales::BeginPlay()
{
	Super::BeginPlay();

	FishLocation = GetActorLocation();
}
void AFishScales::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveToBoat(DeltaTime);
}

void AFishScales::MoveToBoat(float DeltaTime)
{
	FVector ToTarget = (PlayerLocation - FishLocation);
	bool Target = ToTarget.Normalize();
	FVector GoTo = (DeltaTime * MovementRate * (ToTarget * 300));
	GoTo.Z = 0.f;
	AddActorWorldOffset(GoTo);
}

