// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CorridorCombatGameModeBase.generated.h"


UCLASS()
class CORRIDORCOMBAT_API ACorridorCombatGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	virtual void PawnKilled(APawn* DeadPawn);
	
};
