// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"

ATankPawn::ATankPawn()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay()
{
	Super::BeginPlay();

    TankPlayerController = Cast<APlayerController>(GetController());

    if (TankPlayerController)
    {
        if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(TankPlayerController->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(InputMappingContext, 0);
        }
    }
}

// Called to bind functionality to input
void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // Moving
        EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &ATankPawn::Move);

        // Turning
        EnhancedInputComponent->BindAction(TurnInputAction, ETriggerEvent::Triggered, this, &ATankPawn::Turn);

        // Rotating Turret
        EnhancedInputComponent->BindAction(RotateTurretInputAction, ETriggerEvent::Triggered, this, &ATankPawn::RotateTurret);

        // Firing
        EnhancedInputComponent->BindAction(FireInputAction, ETriggerEvent::Triggered, this, &ATankPawn::Fire);
    }
}

void ATankPawn::HandleDestruction()
{
    Super::HandleDestruction();
    SetActorHiddenInGame(true);
    // If Tick ever gets implemented, disable here
}

void ATankPawn::Move(const FInputActionValue& Value)
{
    const float DirectionValue = Value.Get<float>();
    FVector DeltaLocation = FVector::ZeroVector;

    // Forwards or backwards movement (W, S)
    DeltaLocation.X = DirectionValue * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
    AddActorLocalOffset(DeltaLocation, true);
}

void ATankPawn::Turn(const FInputActionValue &Value)
{
    const float DirectionValue = Value.Get<float>();
    FRotator DeltaRotation = FRotator::ZeroRotator;

    // Left and right turning (A, D)
    DeltaRotation.Yaw = DirectionValue * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
    AddActorLocalRotation(DeltaRotation, true);
}

void ATankPawn::RotateTurret(const FInputActionValue &Value)
{
    const float RotateAxisValue = Value.Get<float>();
    FRotator LookAtRotation = FRotator::ZeroRotator;

    // Rotating turret (Mouse X, Left & Right arrow keys)
    LookAtRotation.Yaw = RotateAxisValue * RotationRate * UGameplayStatics::GetWorldDeltaSeconds(this);
    GetTurretMesh()->AddWorldRotation(LookAtRotation);
}
