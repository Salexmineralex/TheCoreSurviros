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

	if(CurrentLife <= 0)
	{
		//TO-DO
		//Kill component owner
		OnKillEntity.Execute();
	}	
}

void ULifeComponent::RestoreAmount_Implementation(float recover)
{


	int auxLife = CurrentLife + recover;

	if(auxLife >= MaxLife)
	{
		auxLife = MaxLife;
	}
	
	CurrentLife = auxLife;
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


