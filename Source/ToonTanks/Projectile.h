// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere)
	float Damage = 50.0f;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	/// @brief 
	/// @param HitComp Component that is hitting
	/// @param OtherActor Actor that got hit
	/// @param OtherComp Component that got hit
	/// @param NormalImpulse Applies impulse at collision location
	/// @param Hit Hit result
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
