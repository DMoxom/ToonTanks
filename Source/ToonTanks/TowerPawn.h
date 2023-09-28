// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "TowerPawn.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATowerPawn : public ABasePawn
{
	GENERATED_BODY()

public:
	ATowerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	class ATankPawn* Tank;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRange = 300.0f;
};
