// Jonathan Moallem 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"


UCLASS()
class CORRIDORCOMBAT_API AGun : public AActor
{
	GENERATED_BODY()
	
public:

    // Constructor & public default functions

	AGun();

	virtual void Tick(float DeltaTime) override;

	// Combat functions

	void PullTrigger(AController* Controller);

protected:

    // Protected default functions

	virtual void BeginPlay() override;

private:

    // Components

    UPROPERTY(VisibleAnywhere)
    USceneComponent* Root;

    UPROPERTY(VisibleAnywhere)
    USkeletalMeshComponent* Mesh;

    UPROPERTY(EditAnywhere)
    UParticleSystem* MuzzleFlash;

    UPROPERTY(EditAnywhere)
    UParticleSystem* ImpactEffect;

    UPROPERTY(EditAnywhere)
    USoundBase* MuzzleSound;

    UPROPERTY(EditAnywhere)
    USoundBase* ImpactSound;

    // Fields

    UPROPERTY(EditAnywhere, Category = "Combat")
    float MaxRange = 1000.f;

    UPROPERTY(EditAnywhere, Category = "Combat")
    float Damage = 10.f;

    // Helper methods

    bool GetGunTrace(AController* Controller, OUT FRotator& StartRotation, OUT FHitResult& Hit);
};
