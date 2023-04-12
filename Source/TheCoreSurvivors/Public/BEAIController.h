// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BEAIController.generated.h"

/**
 * 
 */
UCLASS()
class THECORESURVIVORS_API ABEAIController : public AAIController
{
	GENERATED_BODY()
	

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;

};
