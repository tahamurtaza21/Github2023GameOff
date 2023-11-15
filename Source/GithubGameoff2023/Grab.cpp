// Fill out your copyright notice in the Description page of Project Settings.


#include "Grab.h"
#include "Fish.h"

// Sets default values for this component's properties
UGrab::UGrab()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UGrab::BeginPlay()
{
	Super::BeginPlay();
	SetController();

	FishMesh = Cast<UStaticMeshComponent>(GetChildComponent(0));
	if(FishMesh != nullptr)
	{
		FishMesh->SetVisibility(false);
	}
}


// Called every frame
void UGrab::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ReleaseFish();
}

void UGrab::GrabFish()
{
	FHitResult OutHit;

	FVector StartLocation;
	FRotator StartRotation;

	PlayerController->GetPlayerViewPoint(StartLocation, StartRotation);

	//UE_LOG(LogTemp, Display, TEXT("%s"), *StartLocation.ToCompactString());

	GetWorld()->SweepSingleByChannel(OutHit, StartLocation, StartLocation + (StartRotation.Vector() * 3000), FQuat::Identity, ECC_GameTraceChannel1, FCollisionShape::MakeSphere(20.f));
	
	DrawDebugSphere(GetWorld(), OutHit.ImpactPoint, 20, 5, FColor::Red, false, 2.f);

	if (!isGrabbingFish && &OutHit != nullptr)
	{
		//Add Fish being visible class
		FishHit = Cast<AFish>(OutHit.GetActor());

		if(FishHit != nullptr)
		{
			isGrabbingFish = true;
			FishMesh->SetVisibility(true);	//attached fish visibility on
			//UE_LOG(LogTemp, Display, TEXT("Got Fish"));
			FishHit->SetActorEnableCollision(false);
			FishHit->GetComponentByClass<USkeletalMeshComponent>()->SetVisibility(false); //fish in sea visibility off
			FishHit->Destroy();
		}
		UE_LOG(LogTemp, Display, TEXT("Hit something"));
	}
}

void UGrab::ReleaseFish()
{
	if(isGrabbingFish == false)
	{
		FishMesh->SetVisibility(false);	//attached fish visibility on
	}
}

void UGrab::SetController()
{
	APawn* PlayerPawn = Cast<APawn>(GetOwner());
	PlayerController = PlayerPawn->GetController();

	if (PlayerController == nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("Did not get controller"));
	}
}
