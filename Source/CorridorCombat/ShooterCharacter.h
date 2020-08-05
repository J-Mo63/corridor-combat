// Jonathan Moallem 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

#ifndef PRINT
#define PRINT(text) UE_LOG(LogTemp, Error, TEXT(#text))
#endif


UCLASS()
class CORRIDORCOMBAT_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:

    // Constructor & public default functions

	AShooterCharacter();

    virtual void Tick(float DeltaTime) override;


    // Input binding functions

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveForward(float AxisValue);

    void MoveRight(float AxisValue);

    void LookUp(float AxisValue);

    void LookRight(float AxisValue);

protected:

    // Protected default functions

	virtual void BeginPlay() override;

private:

    // Player input fields

    UPROPERTY(EditAnywhere, Category = "Player Input")
    float LookSpeed = 50.f;

    UPROPERTY(EditAnywhere, Category = "Player Input")
    float MoveSpeed = 100.f;

};
