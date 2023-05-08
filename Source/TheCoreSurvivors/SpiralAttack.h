// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/KismetSystemLibrary.h"
#include <math.h>
#include <vector>
#include "Engine/World.h"
#include "CoreMinimal.h"
#include <Engine/Engine.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GameFramework/FloatingPawnMovement.h>
#include "Components/ActorComponent.h"
#include "SpiralAttack.generated.h"



USTRUCT(BlueprintType)
struct Fsphere_raycast {

	GENERATED_BODY()

	double Radius;
	ETraceTypeQuery TraceChannel;
	bool bTraceComplex;
	TArray<AActor*> ActorsToIgnore;
	EDrawDebugTrace::Type DrawDebugType;
	FHitResult OutHit;

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THECORESURVIVORS_API USpiralAttack : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	
	USpiralAttack();
	void do_spiral();
	void spiral_timer();
	FVector next_spiral_point(double a, double b, double angle);
protected:
	// Called when the game starts
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite) float cooldown = 2.0f;

	bool throw_raycast(FVector point);
	virtual void BeginPlay() override;


	Fsphere_raycast raySphere;
	int spiralOffset{ 70};
	float spiralRotation{ 180 };
	float spiralTimer{2.0f};
	bool flip = true;
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	
};

FVector rotate_point(FVector pivot, float angle, FVector point);