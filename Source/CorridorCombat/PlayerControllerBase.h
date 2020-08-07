// Jonathan Moallem 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "PlayerControllerBase.generated.h"


UCLASS()
class CORRIDORCOMBAT_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:

    virtual void GameHasEnded(AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

protected:

    virtual void BeginPlay() override;

private:

    UPROPERTY(EditAnywhere)
    TSubclassOf<UUserWidget> HUDClass;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UUserWidget> WinScreenClass;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UUserWidget> LoseScreenClass;

    UPROPERTY(EditAnywhere)
    float RestartDelay = 5.f;

    FTimerHandle RestartTimer;

    UUserWidget* HUD;
	
};
