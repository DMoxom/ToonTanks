// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOONTANKS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	float MaxHealth = 100.0f;
	float Health = 0.0f;

	class AToonTanksGameMode* ToonTanksGameMode;

	/// @brief Hurts the specified actor with damage
	/// @param DamagedActor Actor that will be damaged
	/// @param Damage Damage value to apply
	/// @param DamageType Class that describes the damage that was done
	/// @param Instigator Controller responsible for causing the damage (e.g player)
	/// @param DamageCauser Actor that actually caused the damage (e.g the projectile)
	UFUNCTION()
	void DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser);
};
