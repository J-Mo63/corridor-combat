// Jonathan Moallem 2020


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"


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
    if (!Controller) { return; }

    // Run muzzle flash effect on the socket
    UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
    UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));

    FRotator StartRotation;
    FHitResult Hit;

    if (GetGunTrace(Controller, OUT StartRotation, OUT Hit))
    {
        FRotator ImpactDirection = StartRotation.GetInverse();
        AActor* HitActor = Hit.GetActor();
        if (HitActor)
        {
            FPointDamageEvent DamageEvent = FPointDamageEvent(Damage, Hit, ImpactDirection.Vector(), nullptr);
            HitActor->TakeDamage(Damage, DamageEvent, Controller, this);
        }

        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.ImpactPoint, ImpactDirection);
        UGameplayStatics::SpawnSoundAtLocation(GetWorld(), MuzzleSound, Hit.ImpactPoint);
    }
}

bool AGun::GetGunTrace(AController* Controller, OUT FRotator& StartRotation, OUT FHitResult& Hit)
{
    FVector StartLocation;
    Controller->GetPlayerViewPoint(OUT StartLocation, OUT StartRotation);
    FVector EndLocation = StartLocation + StartRotation.Vector() * MaxRange;


    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(this);
    QueryParams.AddIgnoredActor(GetOwner());

    return GetWorld()->LineTraceSingleByChannel(OUT Hit, StartLocation, EndLocation,ECC_GameTraceChannel1, QueryParams);
}