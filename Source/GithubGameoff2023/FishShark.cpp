// Fill out your copyright notice in the Description page of Project Settings.

#include "FishShark.h"
#include "TimerManager.h"
#include "HealthBoat.h"


AFishShark::AFishShark()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFishShark::BeginPlay()
{
	Super::BeginPlay();
	FishPosition = GetActorLocation();
	
	OnTakeAnyDamage.AddDynamic(this, &AFishShark::DamageTaken);
	GetWorldTimerManager().SetTimer(AttackTimer,this,&AFishShark::Attack,AttackTimerRate,true);

	BoatHealth = Boat->GetComponentByClass<UHealthBoat>();
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
		//UE_LOG(LogTemp, Display, TEXT("%f"),FVector::Distance(PlayerLocation,GetActorLocation()));
		FVector GoTo = (DeltaTime * MovementRate * (ToTarget * 1000));
		GoTo.Z = 0.f;
		AddActorWorldOffset(GoTo);
	}
	else
	{
		canAttack = true; //BeginAttacking
	}
}

void AFishShark::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Controller,
	AActor* DamageCauser)
{
	if(Damage > 0.f)
	{
		Health -= Damage;
	}
	if(Health < 0)
	{
		Death();
		canAttack = false;
	}
}

void AFishShark::Death()
{
	Destroy();
}

void AFishShark::Attack()
{
	if(!canAttack)
	{
		return;
	}
	
	BoatHealth->Health -= BiteDamage;
	//UE_LOG(LogTemp,Warning, TEXT("Boat Hit"));

	if(BoatHealth->Health <= 0.f)
	{
		BoatHealth->Death();
		//UE_LOG(LogTemp,Warning, TEXT("DEd"));
		canAttack = false;
	}
}
