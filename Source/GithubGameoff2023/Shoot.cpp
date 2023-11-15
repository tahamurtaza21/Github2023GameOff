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
			SpawnLocation.Z = Grabber->GetComponentLocation().Z;
			SpawnLocation.X = Grabber->GetComponentLocation().X + FMath::FRandRange(-40.f,60.f);
			SpawnLocation.Y = Grabber->GetComponentLocation().Y + FMath::FRandRange(-35.f,35.f);
			SpawnRotation = Grabber->GetComponentRotation();
			SpawnRotation.Yaw += FMath::RandRange(-40,60);

			if(Projectiles != nullptr)
			{
				AProjectileScale* Projectile = GetWorld()->SpawnActor<AProjectileScale>(Projectiles,SpawnLocation,SpawnRotation);
			
				if(Projectile->GetComponentByClass<UPrimitiveComponent>())
				{
					Projectile->GetComponentByClass<UPrimitiveComponent>()->AddImpulse(Grabber->GetForwardVector()*1000);
				}
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

