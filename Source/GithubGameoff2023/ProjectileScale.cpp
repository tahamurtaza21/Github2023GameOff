// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileScale.h"
#include "Kismet/GameplayStatics.h"

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

	ProjectileScaleMesh->OnComponentHit.AddDynamic(this, &AProjectileScale::OnHit);	// we binded this function to call whenever OnComponentHit happens
}

// Called every frame
void AProjectileScale::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectileScale::OnHit(UPrimitiveComponent* HitComp, AActor* OtherHit, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	AController* MyInstigatorController = GetInstigatorController();
	UClass* DamageTypeClass = UDamageType::StaticClass();
	
	if (OtherHit && OtherHit != this)
	{
		UGameplayStatics::ApplyDamage(OtherHit, Damage, MyInstigatorController, this, DamageTypeClass);
		UE_LOG(LogTemp, Display, TEXT("Hit"));
	}
	Destroy();
}

