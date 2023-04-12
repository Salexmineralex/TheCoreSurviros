// Fill out your copyright notice in the Description page of Project Settings.


#include "LifeComponent.h"

#include <algorithm>

#include "Engine/Engine.h"

// Sets default values for this component's properties
ULifeComponent::ULifeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULifeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULifeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(IsDamageOverTime)
	{
		ReduceAmount_Implementation(DamagePerSecond*DeltaTime);
	}

	// ...
}

void ULifeComponent::ReduceAmount_Implementation(float damage)
{

	
	CurrentLife -= damage;

	//TO-DO
	//Change Widget Life Percent

	if(CurrentLife <= 0)
	{
		//TO-DO
		//Kill component owner
		OnKillEntity.Execute();

	}

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("CurrentLife %d"), CurrentLife));
	
}

void ULifeComponent::RestoreAmount_Implementation(float recover)
{
	const int auxLife = CurrentLife + recover;


	if(auxLife >= MaxLife)
	{
		CurrentLife = MaxLife;
	}else
	{
		CurrentLife = auxLife;
	}
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("CurrentLife %d"), CurrentLife));
	//TO-DO
	//Change Widget Life Percent
}

void ULifeComponent::StartDamageOverTime_Implementation(float dps)
{

	DamagePerSecond = dps;
	
	IsDamageOverTime = true;

}

void ULifeComponent::StopDamageOverTime_Implementation()
{
	IsDamageOverTime = false;
}


