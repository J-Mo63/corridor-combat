// Jonathan Moallem 2020


#include "KillEmAllGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"


void AKillEmAllGameMode::PawnKilled(APawn* DeadPawn)
{
    Super::PawnKilled(DeadPawn);

    if (!DeadPawn) { return; }

    AController* Controller = DeadPawn->GetController();

    if (Controller && Controller->IsPlayerController())
    {
        EndGame(false);
    }
    else
    {

        for (AShooterAIController* AiController : TActorRange<AShooterAIController>(GetWorld()))
        {
            if (AiController && !AiController->IsDead()) { return; }
        }
        EndGame(true);
    }
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
        Controller->GameHasEnded(Controller->GetPawn(), Controller->IsPlayerController() && bIsPlayerWinner);
    }
}