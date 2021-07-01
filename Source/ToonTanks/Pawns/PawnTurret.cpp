// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"

APawnTurret::APawnTurret() 
{
    
}

void APawnTurret::BeginPlay() 
{
    Super::BeginPlay();
    GetWorld()->GetTimerManager().SetTimer(FFireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
}

void APawnTurret::Tick(float DeltaTime) 
{
    
}

void APawnTurret::CheckFireCondition() 
{
    
}




