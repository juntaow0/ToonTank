// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnTank.h"
#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"

APawnTurret::APawnTurret() 
{
    
}

void APawnTurret::BeginPlay() 
{
    Super::BeginPlay();
    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::HandleDestruction() 
{
    Super::HandleDestruction();
    Destroy();
}

void APawnTurret::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);
    if (!PlayerPawn||ReturnDistanceToPlayer()>FireRange){
        return;
    }
    RotateTurretFunction(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition() 
{
    if (!PlayerPawn || !PlayerPawn->GetIsPlayerAlive()){
        return;
    }
    if (ReturnDistanceToPlayer()<=FireRange){
        Fire();
        UE_LOG(LogTemp, Warning, TEXT("Fire!"));
    }
}

float APawnTurret::ReturnDistanceToPlayer() 
{
    if (!PlayerPawn){
        return 0.0f;
    }
    return FVector::Dist(PlayerPawn->GetActorLocation(),GetActorLocation());
}




