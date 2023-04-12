// Fill out your copyright notice in the Description page of Project Settings.


#include "BEAIController.h"

void ABEAIController::BeginPlay() 
{

	// Obtenemos el actor a seguir en este caso el player 
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	AActor* PlayerActor = PlayerController->GetPawn();

	// Su posicion
	FVector PosicionActorASeguir = PlayerActor->GetActorLocation();

	// Obtenemos la posicion del pawn controlado
	FVector PosicionEsteActor = GetPawn()->GetActorLocation();

	// Calculamos la dirección y se normaliza
	FVector Direccion = PosicionActorASeguir - PosicionEsteActor;
	Direccion.Normalize();

	float Velocidad = 500.f;

	// Se calcula la nueva posición
	FVector NuevaPosicion = PosicionEsteActor + (Direccion * Velocidad);

	// "MOVE TO 
	GetPawn()->SetActorLocation(NuevaPosicion);
}

void ABEAIController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

	// Obtenemos el actor a seguir en este caso el player 
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	
	AActor* PlayerActor = PlayerController->GetPawn();
	
	// Su posicion
	FVector PosicionActorASeguir = PlayerActor->GetActorLocation();
	
	// Obtenemos la posicion del pawn controlado
	FVector PosicionEsteActor = GetPawn()->GetActorLocation();

	// Calculamos la dirección y se normaliza
	FVector Direccion = PosicionActorASeguir - PosicionEsteActor;
	Direccion.Normalize();

	float Velocidad = 500.f;

	// Se calcula la nueva posición
	FVector NuevaPosicion = PosicionEsteActor + (Direccion * Velocidad * DeltaTime);
	
	// "MOVE TO 
	GetPawn()->SetActorLocation(NuevaPosicion);
}

void ABEAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)  
{
	// Obtenemos el actor a seguir en este caso el player 
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	AActor* PlayerActor = PlayerController->GetPawn();

	// Su posicion
	FVector PosicionActorASeguir = PlayerActor->GetActorLocation();

	// Obtenemos la posicion del pawn controlado
	FVector PosicionEsteActor = GetPawn()->GetActorLocation();

	// Calculamos la dirección y se normaliza
	FVector Direccion = PosicionActorASeguir - PosicionEsteActor;
	Direccion.Normalize();

	float Velocidad = 500.f;

	// Se calcula la nueva posición
	FVector NuevaPosicion = PosicionEsteActor + (Direccion * Velocidad);

	// "MOVE TO 
	GetPawn()->SetActorLocation(NuevaPosicion);
}