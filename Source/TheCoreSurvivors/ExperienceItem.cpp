// Fill out your copyright notice in the Description page of Project Settings.


#include "ExperienceItem.h"

// Sets default values
AExperienceItem::AExperienceItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExperienceItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExperienceItem::Init(float newValue)
{
	experiencedGained = newValue;
}


// Called every frame
void AExperienceItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

