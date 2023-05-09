// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "_dataRaul/ThrowableKnife.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "ThrowableKnifeSpawnerComponent.generated.h"


class  AThrowableKnife;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THECORESURVIVORS_API UThrowableKnifeSpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UThrowableKnifeSpawnerComponent();

	UFUNCTION(BlueprintCallable)
		void SpawnProjectile();

	UFUNCTION(BlueprintCallable)
		void StartSpawning();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float offset = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float intervalSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor>knifeActor;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	AThrowableKnife* knife;
	FTimerHandle spawningTimerHandle;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
