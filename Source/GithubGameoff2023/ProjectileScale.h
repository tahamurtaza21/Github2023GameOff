// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileScale.generated.h"

UCLASS()
class GITHUBGAMEOFF2023_API AProjectileScale : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileScale();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float Damage = 5.f;

	float TimePassed;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ProjectileScaleMesh;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherHit, UPrimitiveComponent* OtherComp,FVector NormalImpulse,const FHitResult& Hit);

	void DestroyTheScale();
};
