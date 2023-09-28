// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerPawn.h"
#include "TankPawn.h"
#include "Kismet/GameplayStatics.h"

ATowerPawn::ATowerPawn()
{

}

void ATowerPawn::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void ATowerPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //TODO: Un-nest if statements
    if (Tank)
    {
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation()); 

        if (Distance <= FireRange)
        {
            RotateTurretToTarget(Tank->GetActorLocation(), 20.0f);
        } 
    }
}
