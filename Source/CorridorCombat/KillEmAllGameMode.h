// Jonathan Moallem 2020

#pragma once

#include "CoreMinimal.h"
#include "CorridorCombatGameModeBase.h"
#include "KillEmAllGameMode.generated.h"


UCLASS()
class CORRIDORCOMBAT_API AKillEmAllGameMode : public ACorridorCombatGameModeBase
{
	GENERATED_BODY()

public:

    virtual void PawnKilled(APawn* DeadPawn) override;

private:

    void EndGame(bool bIsPlayerWinner);

};
