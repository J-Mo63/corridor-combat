// Jonathan Moallem 2020


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "CorridorCombat.h"


AGun::AGun()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AGun::BeginPlay()
{
	Super::BeginPlay();
}

void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGun::PullTrigger(AController* Controller)
{
    // Run muzzle flash effect on the socket
    UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));

    FVector StartLocation;
    FRotator StartRotation;
    Controller->GetPlayerViewPoint(OUT StartLocation, OUT StartRotation);
    FVector EndLocation = StartLocation + StartRotation.Vector() * MaxRange;

    FHitResult Hit;
    bool bHit = GetWorld()->LineTraceSingleByChannel(OUT Hit, StartLocation, EndLocation, ECC_GameTraceChannel1);

    if (bHit)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.ImpactPoint,
                                                 StartRotation.GetInverse());
    }
}