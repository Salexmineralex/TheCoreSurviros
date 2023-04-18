

#include "BaseEnemy.h"

// Sets default values
ABaseEnemy::ABaseEnemy(const FObjectInitializer& ObjectInitializer):

	// Crowd AI Controller 
	Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("CrowdAIPathFollowingComponent")))

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
	
	isColliding = false;
	
	// Asign a controller
	AIControllerClass = ABEAIController::StaticClass();
	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ABaseEnemy::BeginOverlap);


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


void ABaseEnemy::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult) 
{
	isColliding = true;

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Entrado")));
	// Comprueba que el actor que ha entrado en contacto es válido
	if (OtherActor != nullptr)
	{
		ILifeManagerInterface* LifeManager = Cast<ILifeManagerInterface>(OtherActor);


		if (LifeManager)
		{
			LifeManager->Execute_ReduceAmount(OtherActor, NormalDamage);
		}

	}
}
void ABaseEnemy::EndOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	isColliding = false;
}
;

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	if (isColliding) 
	{
		// Ejecutar daño con el tiempo
	}
}
