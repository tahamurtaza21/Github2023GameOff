// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fish.h"
#include "FishScales.generated.h"

/**
 * 
 */
UCLASS()
class GITHUBGAMEOFF2023_API AFishScales : public AFish
{
	GENERATED_BODY()

public:
	float AmountofScales = 6.f;
	AFishScales();

private:
	UFUNCTION(BlueprintCallable)
	void Jump();
	
};
