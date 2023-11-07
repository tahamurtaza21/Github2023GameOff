// Fill out your copyright notice in the Description page of Project Settings.


#include "Fish.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFish::AFish()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FishMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Fish Mesh"));
	RootComponent = FishMesh;
}

// Called when the game starts or when spawned
void AFish::BeginPlay()
{
	Super::BeginPlay();

	PlayerLocation = UGameplayStatics::GetPlayerPawn(this, 0)->GetActorLocation();
	
}

// Called every frame
void AFish::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//SetActorLocation()
	RotateFishToBoat();
	MoveToBoat((DeltaTime));
	DestroyItself();
}

void AFish::DestroyItself()
{
	if(toDestroy)
	{
		Destroy();
	}
}

void AFish::MoveToBoat(float DeltaTime)
{
	FVector ToTarget = PlayerLocation - GetActorLocation();
	FVector GoTo = DeltaTime * MovementRate * ToTarget;
	GoTo.Z = 0.f;
	AddActorWorldOffset(GoTo);
}


void AFish::RotateFishToBoat()
{
	FVector ToTarget = PlayerLocation - GetActorLocation();
	FRotator LookAt = FRotator(0, ToTarget.Rotation().Yaw - 90 , 0);
	FishMesh->SetWorldRotation(FMath::RInterpTo(FishMesh->GetComponentRotation(),
		LookAt, 
		UGameplayStatics::GetWorldDeltaSeconds(this),
		5));
}
