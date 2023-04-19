// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnActorsComponent.h"
#include "GameFramework/Actor.h"
#include <random>

#include "TimerManager.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
// Sets default values for this component's properties
USpawnActorsComponent::USpawnActorsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpawnActorsComponent::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle SpawnHandleNorth;
	FTimerHandle SpawnHandleWest;
	FTimerHandle SpawnHandleEast;
	FTimerHandle SpawnHandleSouth;


	FTimerDelegate Delegate; // Delegate to bind function with parameters
	Delegate.BindUFunction(this, "SpawnActor", North);
	

	GetWorld()->GetTimerManager().SetTimer(SpawnHandleNorth, Delegate, TimeBeforeSpawn,true);

	Delegate.BindUFunction(this, "SpawnActor", West);
	GetWorld()->GetTimerManager().SetTimer(SpawnHandleWest, Delegate, TimeBeforeSpawn,true);

	Delegate.BindUFunction(this, "SpawnActor", East);
	GetWorld()->GetTimerManager().SetTimer(SpawnHandleEast, Delegate, TimeBeforeSpawn,true);

	Delegate.BindUFunction(this, "SpawnActor", South);
	GetWorld()->GetTimerManager().SetTimer(SpawnHandleSouth, Delegate, TimeBeforeSpawn,true);
	
}


// Called every frame
void USpawnActorsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FVector USpawnActorsComponent::GetNewLocation(FVector directon)
{
	float xOffset = (FMath::FRand() - 0.5f) * N;
	float yOffset = (FMath::FRand() - 0.5f) * M;
	
	FVector offset = FVector(xOffset*directon.X, yOffset*directon.Y, 0.0f);

	offset += GetOwner()->GetActorLocation();
	return FVector(offset);
	
}


FVector USpawnActorsComponent::GetCompassDirecton(Compass direction)
{
	switch (direction)
	{
		case Compass::North: return GetOwner()->GetActorForwardVector(); break;	
		case Compass::West: return -GetOwner()->GetActorRightVector(); break;
		case Compass::South:return -GetOwner()->GetActorForwardVector(); break;
		case Compass::East: return GetOwner()->GetActorRightVector(); break;
	}
	return FVector();
}

void USpawnActorsComponent::SpawnActor(Compass direction)
{

	

	FVector spawnPosition = GetNewLocation(GetCompassDirecton(direction));
	GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Yellow, spawnPosition.ToString());

	FActorSpawnParameters SpawnInfo;

	GetWorld()->SpawnActor<AActor>(ActorToSpawn,spawnPosition,GetOwner()->GetActorRotation(),SpawnInfo);
	
}



