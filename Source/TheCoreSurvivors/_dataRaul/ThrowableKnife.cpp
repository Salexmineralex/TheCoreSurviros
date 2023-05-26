// Fill out your copyright notice in the Description page of Project Settings.


#include "TheCoreSurvivors/_dataRaul/ThrowableKnife.h"
#include "TheCoreSurvivors/LifeManagerInterface.h"

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

	boxComponent->OnComponentBeginOverlap.AddDynamic(this, &AThrowableKnife::BeginOverlap);

}

// Called every frame
void AThrowableKnife::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AThrowableKnife::BeginOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (otherActor != nullptr)
	{
		ILifeManagerInterface* LifeManager = Cast<ILifeManagerInterface>(otherActor);

		if (LifeManager)
		{
			LifeManager->Execute_ReduceAmount(otherActor, this->damage);
			this->Destroy();
		}
	}
}
