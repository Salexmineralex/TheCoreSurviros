

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
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	//
}
