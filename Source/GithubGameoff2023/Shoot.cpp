// Fill out your copyright notice in the Description page of Project Settings.


#include "Shoot.h"
#include "Grab.h"
#include "Components/PrimitiveComponent.h"

// Sets default values for this component's properties
UShoot::UShoot()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UShoot::BeginPlay()
{
	Super::BeginPlay();

	Grabber = GetOwner()->FindComponentByClass<UGrab>();
}


// Called every frame
void UShoot::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UShoot::ShootScales()
{
	if(Grabber && Grabber->isGrabbingFish == true && AmountOfTimesToShoot > 0)
	{
		for(int i = 0; i < ProjectilesCount; i++)
		{
			AProjectileScale* Projectile = GetWorld()->SpawnActor<AProjectileScale>(Projectiles,SpawnLocation,SpawnRotation);
			SpawnLocation = Grabber->GetComponentLocation() + FMath::RandRange(5,15);
			SpawnRotation = Grabber->GetComponentRotation();
			SpawnRotation.Yaw += FMath::RandRange(0,20);
			if(Projectile->GetComponentByClass<UPrimitiveComponent>())
			{
				Projectile->GetComponentByClass<UPrimitiveComponent>()->AddImpulse(Grabber->GetForwardVector()*500);
			}
			
		}
		AmountOfTimesToShoot--;
		if(AmountOfTimesToShoot <= 0)
		{
			Grabber->isGrabbingFish = false;
			AmountOfTimesToShoot = 6;
		}
	}
}

