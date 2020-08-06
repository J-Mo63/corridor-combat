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

    // Constructor & public default functions

	AShooterCharacter();

    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

    // Protected default functions

	virtual void BeginPlay() override;

private:

    // Components

    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    TSubclassOf<AGun> GunClass;

    UPROPERTY()
    AGun* Gun;

    // Player input fields

    UPROPERTY(EditAnywhere, Category = "Player Input")
    float LookSpeed = 50.f;

    UPROPERTY(EditAnywhere, Category = "Player Input")
    float MoveSpeed = 100.f;

    // Combat functions

    void Shoot();

    // Input binding functions

    void MoveForward(float AxisValue);

    void MoveRight(float AxisValue);

    void LookUp(float AxisValue);

    void LookRight(float AxisValue);

};
