// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Grab.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GITHUBGAMEOFF2023_API UGrab : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrab();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	bool isGrabbingFish = false;
private:

	AController* PlayerController;

	UStaticMeshComponent* FishMesh;

	void SetController();
	
	class AFish* FishHit;

	UFUNCTION(BlueprintCallable)
	void GrabFish();

	void ReleaseFish();
};
