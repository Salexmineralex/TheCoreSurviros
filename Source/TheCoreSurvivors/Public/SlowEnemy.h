// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseEnemy.h"
#include "SlowEnemy.generated.h"

/**
 * 
 */
UCLASS()
class THECORESURVIVORS_API ASlowEnemy : public ABaseEnemy
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

};
