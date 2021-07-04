// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;
class AProjectileBase;
class UHealthComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnBase();
	virtual void HandleDestruction();

protected:
	// for collision
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components", meta=(AllowPrivateAccess="true"))			
	UCapsuleComponent* CapsuleComp = nullptr;
	void RotateTurretFunction(FVector LookAtTarget);
	void Fire();

private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* BaseMesh = nullptr;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* TurretMesh = nullptr;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components", meta=(AllowPrivateAccess="true"))
	USceneComponent* ProjectileSpawnPoint = nullptr;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components", meta=(AllowPrivateAccess="true"))
	UHealthComponent* HealthComp = nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Projectile Type", meta=(AllowPrivateAccess="true"))
	TSubclassOf<AProjectileBase> ProjectileClass;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effects", meta=(AllowPrivateAccess="true"))
	UParticleSystem* DeathParticle = nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effects", meta=(AllowPrivateAccess="true"))
	USoundBase* DestructionSound = nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite ,Category="Effects", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UMatineeCameraShake> DeathShake;
};
