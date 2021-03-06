// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"
#include "../Actors/ProjectileBase.h"
#include "../Components/HealthComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

void APawnBase::RotateTurretFunction(FVector LookAtTarget) 
{

	FVector LookDirection = FVector(LookAtTarget.X,LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);
	FVector StartLocation = TurretMesh->GetComponentLocation();
	FRotator TurretRotation = (LookDirection-StartLocation).Rotation();
	// add animation in the future!!!
	TurretMesh->SetWorldRotation(TurretRotation);
}

void APawnBase::Fire() 
{
	if (ProjectileClass){
		AProjectileBase * TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass,ProjectileSpawnPoint->GetComponentLocation(),TurretMesh->GetComponentRotation());
		TempProjectile->SetOwner(this);
	}
}

void APawnBase::HandleDestruction() 
{
	UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticle, GetActorLocation());
	UGameplayStatics::PlaySoundAtLocation(this, DestructionSound, GetActorLocation());
	GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathShake);
}





