// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "TankPawn.h"
#include "TowerPawn.h"

void AToonTanksGameMode::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AToonTanksGameMode::ActorDied(AActor *DeadActor)
{
    if (DeadActor == Tank)
    {
        Tank->HandleDestruction();
        if (Tank->GetTankPlayerController())
        {
            Tank->DisableInput(Tank->GetTankPlayerController());
            Tank->GetTankPlayerController()->bShowMouseCursor = false;
        }
    }
    else if (ATowerPawn* DestroyedTower = Cast<ATowerPawn>(DeadActor))
    {
        DestroyedTower->HandleDestruction();
    }

    // if (DeadActor != Tank)
    // {
    //     return;
    // }

    // Tank->HandleDestruction();
    // if (Tank->GetTankPlayerController())
    // {
    //     Tank->DisableInput(Tank->GetTankPlayerController());
    //     Tank->GetTankPlayerController()->bShowMouseCursor = false;
    // }
}
