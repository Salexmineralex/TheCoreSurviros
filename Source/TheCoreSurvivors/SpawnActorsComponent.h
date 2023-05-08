// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnActorsComponent.generated.h"

UENUM(BlueprintType)
enum Compass
{
	North,
	East,
	West,
	South
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THECORESURVIVORS_API USpawnActorsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnActorsComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float N;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float M;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorToSpawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeBeforeSpawn;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	FVector GetNewLocation(FVector direction);

	UFUNCTION()
	FVector GetCompassDirecton(Compass direction);

	UFUNCTION()
	void SpawnActor(Compass direction);
	
	TMap<Compass,float> SpawnRatios;
		
};




