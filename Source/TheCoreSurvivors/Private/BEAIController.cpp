// Fill out your copyright notice in the Description page of Project Settings.


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
	
	
	//// Obtenemos el actor a seguir en este caso el player 
	//APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	//
	//AActor* PlayerActor = PlayerController->GetPawn();
	//
	//// Su posicion
	//FVector PosicionActorASeguir = PlayerActor->GetActorLocation();
	//
	//// Obtenemos la posicion del pawn controlado
	//FVector PosicionEsteActor = GetPawn()->GetActorLocation();

	//// Calculamos la direcci�n y se normaliza
	//FVector Direccion = PosicionActorASeguir - PosicionEsteActor;
	//Direccion.Normalize();

	//float Velocidad = 200.f;

	//// Se calcula la nueva posici�n
	//FVector NuevaPosicion = PosicionEsteActor + (Direccion * Velocidad * DeltaTime);
	//
	//// "MOVE TO 
	//GetPawn()->SetActorLocation(NuevaPosicion);
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
