// Fill out your copyright notice in the Description page of Project Settings.


#include "FishShark.h"


AFishShark::AFishShark()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFishShark::BeginPlay()
{
	Super::BeginPlay();
	FishPosition = GetActorLocation();
}

void AFishShark::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveToBoat(DeltaTime);
}

void AFishShark::MoveToBoat(float DeltaTime)
{
	FVector ToTarget = PlayerLocation - FishPosition;
	bool Target = ToTarget.Normalize();
	
	if(Target && FVector::DistSquared(PlayerLocation,GetActorLocation()) > NearBoat*NearBoat)
	{
		UE_LOG(LogTemp, Display, TEXT("%f"),FVector::Distance(PlayerLocation,GetActorLocation()));
		FVector GoTo = (DeltaTime * MovementRate * (ToTarget * 1000));
		GoTo.Z = 0.f;
		AddActorWorldOffset(GoTo);
	}
	else
	{
		Attack(); //BeginAttacking
	}
	
}
void AFishShark::Attack()
{
	
}