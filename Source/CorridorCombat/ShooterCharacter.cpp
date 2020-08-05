// Jonathan Moallem 2020


#include "ShooterCharacter.h"
#include "Components/InputComponent.h"


AShooterCharacter::AShooterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}


void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
}


void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooterCharacter::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooterCharacter::MoveRight);
    PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AShooterCharacter::LookUp);
    PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &AShooterCharacter::LookRight);
    PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
}

void AShooterCharacter::MoveForward(float AxisValue)
{
    AddMovementInput(GetActorForwardVector(), AxisValue * MoveSpeed * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::MoveRight(float AxisValue)
{
    AddMovementInput(GetActorRightVector(), AxisValue * MoveSpeed * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::LookUp(float AxisValue)
{
    AddControllerPitchInput(AxisValue * LookSpeed * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::LookRight(float AxisValue)
{
    AddControllerYawInput(AxisValue * LookSpeed * GetWorld()->GetDeltaSeconds());
}