// Fill out your copyright notice in the Description page of Project Settings.


#include "BEAIController.h"

void ABEAIController::BeginPlay() 
{
	// do Move to here

	FVector MyCharacterPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	MoveToLocation(MyCharacterPosition);
}

void ABEAIController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

	FVector MyCharacterPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	MoveToLocation(MyCharacterPosition);
}

void ABEAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)  
{
	/*FVector MyCharacterPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	MoveToLocation(MyCharacterPosition);*/
}