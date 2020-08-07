// Jonathan Moallem 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"


// Forward declarations
class AGun;


UCLASS()
class CORRIDORCOMBAT_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:

    // Constructor & public default methods

	AShooterCharacter();

    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
                             class AController* EventInstigator, AActor* DamageCauser) override;

    // Public methods

    void Shoot();

    UFUNCTION(BlueprintPure)
    bool IsDead() const;

protected:

    // Protected default methods

	virtual void BeginPlay() override;

private:

    // Components

    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    TSubclassOf<AGun> GunClass;

    UPROPERTY()
    AGun* Gun;

    // Health fields

    UPROPERTY(EditAnywhere, Category = "Health")
    float MaxHealth = 100.f;

    float CurrentHealth = 0.f;

    // Player input fields

    UPROPERTY(EditAnywhere, Category = "Player Input")
    float LookSpeed = 50.f;

    UPROPERTY(EditAnywhere, Category = "Player Input")
    float MoveSpeed = 100.f;

    // Input binding methods

    void MoveForward(float AxisValue);

    void MoveRight(float AxisValue);

    void LookUp(float AxisValue);

    void LookRight(float AxisValue);

};
