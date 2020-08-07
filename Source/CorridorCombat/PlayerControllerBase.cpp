// Jonathan Moallem 2020


#include "PlayerControllerBase.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "CorridorCombat.h"
#include "ShooterCharacter.h"


void APlayerControllerBase::BeginPlay()
{
    Super::BeginPlay();

    HUD = CreateWidget(this, HUDClass);
    if (HUD)
    {
        HUD->AddToViewport();
    }
}


void APlayerControllerBase::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    HUD->RemoveFromViewport();

    UUserWidget* DisplayScreen = CreateWidget(this, bIsWinner ? WinScreenClass : LoseScreenClass);
    if (DisplayScreen)
    {
        DisplayScreen->AddToViewport();
    }

    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}