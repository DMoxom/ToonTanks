// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerPawn.h"
#include "TankPawn.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

ATowerPawn::ATowerPawn()
{

}

void ATowerPawn::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATowerPawn::CheckFireCondition, FireRate, true);
}

void ATowerPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (InFireRange())
    {
        RotateTurretToTarget(Tank->GetActorLocation(), 20.0f);
    } 
}

bool ATowerPawn::InFireRange()
{  
    if (!Tank)
    {
        UE_LOG(LogTemp, Warning, TEXT("No tank player pawn in scene"));
        return false;
    }

    float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
    if (Distance <= FireRange)
    {
        return true;
    }
    return false;
}

void ATowerPawn::CheckFireCondition()
{
    if (InFireRange())
    {
        Fire();
    }
}
