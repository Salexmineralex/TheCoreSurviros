
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

	MoveToActor(Target);

	
}

void ABEAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)  
{
	
}

void ABEAIController::OnBoxOverlapBegin(class UPrimitiveComponent* overlappedComponent, class AActor* otherActor,
	class UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep,
	const FHitResult& sweepResult) 
{
	// Comprueba que el actor que ha entrado en contacto es v�lido
	if (otherActor != nullptr)
	{
		
		//// Comprueba que el actor tiene un componente LifeManagerInterface
		////ULifeManagerInterface* lifeManager = Cast<ULifeManagerInterface>(otherActor->GetComponentByClass(ULifeManagerInterface::StaticClass()));
		//if (lifeManager != nullptr)
		//{
		//	// Llama al m�todo hacer da�o del LifeManagerInterface pas�ndole el actor que ha entrado en contacto
		//	lifeManager->hacerDa�o(otherActor);
		//}
	}
}
