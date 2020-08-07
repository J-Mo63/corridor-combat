// Jonathan Moallem 2020


#include "BTService_PlayerLocationIfSeen.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"


UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
    NodeName = "Update Player Location If Seen";
}


void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
    APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    AAIController* AiController = OwnerComp.GetAIOwner();

    if (!Player || !AiController || !BlackboardComponent) { return; }

    if (AiController->LineOfSightTo(Player))
    {
        BlackboardComponent->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
    }
    else
    {
        BlackboardComponent->ClearValue(GetSelectedBlackboardKey());
    }
}