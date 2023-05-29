// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstAidKitItem.h"

// Sets default values
AFirstAidKitItem::AFirstAidKitItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFirstAidKitItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFirstAidKitItem::Init(float newValue)
{
	lifeRecovered = newValue;
}



// Called every frame
void AFirstAidKitItem::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

}

