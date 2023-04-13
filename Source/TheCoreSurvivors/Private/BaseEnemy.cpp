// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"

// Sets default values
ABaseEnemy::ABaseEnemy()
{
 	
	//Create the root 
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;
	
	//Create the staticMesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	
	//Create the Collider
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Collider->SetupAttachment(RootComponent);

	// Asign a controller
	AIControllerClass = ABEAIController::StaticClass();

	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	


	Super::BeginPlay();

	// Obtener una referencia al Controlador personalizado
	ABEAIController* EnemyController = Cast<ABEAIController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (Controller)
	{
		// Obtener una referencia al Pawn personalizado
		ABaseEnemy* MyPawn = Cast<ABaseEnemy>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

		if (MyPawn)
		{
			// Asignar el Pawn personalizado al Controlador personalizado
			Controller->Possess(MyPawn);
		}
	}
	//APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();	

	//AActor* PlayerActor = PlayerController->GetPawn();

	//Target = PlayerActor;


	//if (Target != nullptr) 
	//{
	//	StartLocation = GetActorLocation();

	//	Direction = Target->GetActorLocation() - StartLocation;

	//	TotalDistance = Direction.Size();

	//	UE_LOG(LogTemp, Warning, TEXT("ABaseEnemy TotalDistance = %f"), TotalDistance);

	//	// Get Normal Direction
	//	Direction = Direction.GetSafeNormal();
	//	CurrentDistance = 0.0f;
	//}
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	/*Super::Tick(DeltaTime);

	if (Target != nullptr) 
	{	
		if (CurrentDistance < TotalDistance) 
		{
			FVector Location = GetActorLocation();

			Location += Direction * MovementSpeed * DeltaTime;

			SetActorLocation(Location);

			CurrentDistance = (Location - StartLocation).Size();
		}
	}*/
}
