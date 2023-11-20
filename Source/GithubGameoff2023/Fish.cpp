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
	FishLocation = GetActorLocation();

	TSubclassOf<ABoat> BoatClass = ABoat::StaticClass();
	Boat = Cast<ABoat>(UGameplayStatics::GetActorOfClass(this, BoatClass));
	
	if(Boat != nullptr)
	{
		PlayerLocation = Boat->GetActorLocation();
		//UE_LOG(LogTemp,Display, TEXT("Got Locaiton %s"),*PlayerLocation.ToCompactString() );
	}
	RotateFishToBoat();
}

// Called every frame
void AFish::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFish::RotateFishToBoat()
{
	FVector ToTarget = PlayerLocation - FishLocation;
	FRotator LookAt = FRotator(0, ToTarget.Rotation().Yaw - 90 , 0);
	FishMesh->SetWorldRotation(LookAt);
}
