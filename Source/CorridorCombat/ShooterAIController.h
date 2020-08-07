// Jonathan Moallem 2020

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"


UCLASS()
class CORRIDORCOMBAT_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

public:

    // Constructor & public default methods

    virtual void Tick(float DeltaTime) override;

	// Public functions

	bool IsDead() const;

protected:

    // Protected default methods

    virtual void BeginPlay() override;

private:

    // Component fields

    UPROPERTY()
    UBlackboardComponent* BlackboardComponent;

    // Behaviour fields

    UPROPERTY(EditAnywhere, Category = "Behaviour")
    UBehaviorTree* AIBehaviour;

    // Other fields

    APawn* Player;
	
};
