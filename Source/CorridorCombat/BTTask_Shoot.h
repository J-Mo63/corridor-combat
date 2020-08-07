// Jonathan Moallem 2020

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Shoot.generated.h"


UCLASS()
class CORRIDORCOMBAT_API UBTTask_Shoot : public UBTTaskNode
{
	GENERATED_BODY()

public:

    UBTTask_Shoot();

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
