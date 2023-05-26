// Fill out your copyright notice in the Description page of Project Settings.


#include "ThrowableKnifeSpawnerComponent.h"

// Sets default values for this component's properties
UThrowableKnifeSpawnerComponent::UThrowableKnifeSpawnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	knife = nullptr;
	// ...
}


// Called when the game starts
void UThrowableKnifeSpawnerComponent::BeginPlay()
{
	Super::BeginPlay();	
	StartSpawning();
}


// Called every frame
void UThrowableKnifeSpawnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UThrowableKnifeSpawnerComponent::StartSpawning()
{
	FTimerManager& timerManager = GetWorld()->GetTimerManager();
	timerManager.SetTimer(spawningTimerHandle, this, &UThrowableKnifeSpawnerComponent::SpawnProjectile, intervalSeconds, true);
}


void UThrowableKnifeSpawnerComponent::SpawnProjectile()
{
	AActor* ownerActor = GetOwner();
	FVector launchDirection = GetOwner()->GetActorForwardVector();
	launchDirection *= offset;
	//UClass* knifeClass = StaticLoadClass(AThrowableKnife::StaticClass(), nullptr, TEXT("Blueprint'Content/_dataRaul/Blueprints/BP_Knife.uasset'"));
	
	
	//UClass* knifeClass2 = StaticLoadClass(AThrowableKnife::StaticClass(), nullptr, TEXT("Blueprint'TheCoreSurvivors/Content/_dataRaul/Blueprints/BP_Knife.uasset'"));
	//if (knifeClass)knifeClass = knifeClass2;
	

	if (ownerActor != nullptr)
	{
		
		FVector ownerLocation = ownerActor->GetActorLocation();
		FTransform transform;
		
		transform.SetRotation(GetOwner()->GetActorRotation().Quaternion());
		ownerLocation += launchDirection;
		transform.SetLocation(ownerLocation);

		if (knifeActor)
		{
			FActorSpawnParameters spawnParameters;
			AActor* spawnedKnife = GetWorld()->SpawnActor<AThrowableKnife>(knifeActor, transform, spawnParameters);
		}
		/*if (!knife)
		{
			knife = GetWorld()->SpawnActor<AThrowableKnife>(ownerLocation, launchDirection.Rotation());
		}*/
	}
	
}

/*void UThrowableKnifeSpawnerComponent::StopSpawning()
{
	FTimerManager& timerManager = GetWorld()->GetTimerManager();
	timerManager.ClearTimer(spawningTimerHandle);
}*/