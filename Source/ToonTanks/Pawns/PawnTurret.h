// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnTurret();
	virtual void HandleDestruction() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

private:
	void CheckFireCondition();
	float ReturnDistanceToPlayer();
	FTimerHandle FireRateTimerHandle;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combat", meta=(AllowPrivateAccess="true"))
	float FireRate = 2.0f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combat", meta=(AllowPrivateAccess="true"))
	float FireRange = 500.0f;

	APawnTank* PlayerPawn = nullptr;
};
