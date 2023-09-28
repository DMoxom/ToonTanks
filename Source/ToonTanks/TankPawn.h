// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "InputAction.h"
#include "TankPawn.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATankPawn : public ABasePawn
{
	GENERATED_BODY()

public:
	ATankPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputAction* MoveInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputAction* TurnInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputAction* RotateTurretInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputAction* FireInputAction;

	void Move(const FInputActionValue& Value);
	void Turn(const FInputActionValue& Value);

	void RotateTurret(const FInputActionValue& Value);

	void Fire();

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 200.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 45.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotationRate = 45.0f;

	APlayerController* PlayerControllerRef;
};
