// Jonathan Moallem 2020


#include "ShooterCharacter.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Gun.h"
#include "Components/CapsuleComponent.h"
#include "CorridorCombatGameModeBase.h"


AShooterCharacter::AShooterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}


void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

    CurrentHealth = MaxHealth;

    Gun = GetWorld()->SpawnActor<AGun>(GunClass);
    GetMesh()->HideBoneByName(TEXT("weapon_r"), PBO_None);

    if (Gun)
    {
        Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("weapon_socket"));
        Gun->SetOwner(this);
    }
}


void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


float AShooterCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
                                    class AController* EventInstigator, AActor* DamageCauser)
{
    DamageAmount = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
    CurrentHealth -= FMath::Min(CurrentHealth, DamageAmount);

    if (IsDead())
    {
        ACorridorCombatGameModeBase* GameMode = Cast<ACorridorCombatGameModeBase>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->PawnKilled(this);
        }

        DetachFromControllerPendingDestroy();
        GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    }

    return CurrentHealth;
}


bool AShooterCharacter::IsDead() const
{
    return CurrentHealth <= 0;
}

float AShooterCharacter::GetHealthPercent() const
{
    return CurrentHealth / MaxHealth;
}


void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooterCharacter::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooterCharacter::MoveRight);
    PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AShooterCharacter::LookUp);
    PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &AShooterCharacter::LookRight);
    PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
    PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &AShooterCharacter::Shoot);
}


void AShooterCharacter::Shoot()
{
    if (Gun)
    {
        Gun->PullTrigger(GetController());
    }
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