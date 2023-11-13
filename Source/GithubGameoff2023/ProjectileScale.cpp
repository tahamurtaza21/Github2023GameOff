// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileScale.h"

// Sets default values
AProjectileScale::AProjectileScale()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileScaleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Fish Scale Mesh"));
	ProjectileScaleMesh->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AProjectileScale::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProjectileScale::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

