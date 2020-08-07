// Jonathan Moallem 2020


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "BehaviorTree/BlackboardComponent.h"


void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    if (AIBehaviour)
    {
        RunBehaviorTree(AIBehaviour); // WARNING: MUST SET THIS BEFORE ACCESSING THE BLACKBOARD
        BlackboardComponent = GetBlackboardComponent();
    }

    Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    APawn* AIPawn = GetPawn();
    if (AIPawn)
    {
        BlackboardComponent->SetValueAsVector(TEXT("StartLocation"), AIPawn->GetActorLocation());
    }
}


void AShooterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}