
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "../LifeManagerInterface.h"
#include "BEAIController.generated.h"


/**
 * 
 */
UCLASS()
class THECORESURVIVORS_API ABEAIController : public AAIController
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseEnemy")
		float MovementSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;


	FVector Direction;

	float TotalDistance;
	float CurrentDistance;
	FVector StartLocation;

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "BaseEnemy")
		class AActor* Target;
};
