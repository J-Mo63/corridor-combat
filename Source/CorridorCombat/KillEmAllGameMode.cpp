// Jonathan Moallem 2020


#include "KillEmAllGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "CorridorCombat.h"


void AKillEmAllGameMode::PawnKilled(APawn* DeadPawn)
{
    //APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    //Controller->GameHasEnded();

    PRINT("A pawn was killed")
}