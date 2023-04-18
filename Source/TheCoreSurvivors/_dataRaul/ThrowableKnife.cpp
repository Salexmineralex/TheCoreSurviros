// Fill out your copyright notice in the Description page of Project Settings.


#include "TheCoreSurvivors/_dataRaul/ThrowableKnife.h"

// Sets default values
AThrowableKnife::AThrowableKnife()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	root = CreateDefaultSubobject<USphereComponent>(TEXT("root"));
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("staticMesh"));

	boxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComponent"));
	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("projectileMovement"));


	//RootComponent = staticMesh
	boxComponent->SetupAttachment(root);
	staticMesh->SetupAttachment(root);

}

// Called when the game starts or when spawned
void AThrowableKnife::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AThrowableKnife::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

