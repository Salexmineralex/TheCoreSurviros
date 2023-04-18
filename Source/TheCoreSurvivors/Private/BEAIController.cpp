
#include "BEAIController.h"
void ABEAIController::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	AActor* PlayerActor = PlayerController->GetPawn();

	Target = PlayerActor;
}

void ABEAIController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

	MoveToActor(Target,70,false);

	
}

void ABEAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)  
{

}
