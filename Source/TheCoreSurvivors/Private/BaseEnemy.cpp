

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
	
	isColliding = false;
	
	// MovementComponent
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	MovementComponent->MaxSpeed = MovementSpeed;

	//	Life Component
	_LifeComponent = CreateDefaultSubobject<ULifeComponent>(TEXT("LifeComponent"));


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	MovementComponent->MaxSpeed = MovementSpeed;
	_LifeComponent->MaxLife = TotalLife;
	
	
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	AActor* PlayerActor = PlayerController->GetPawn();

	Target = PlayerActor;

		
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ABaseEnemy::BeginOverlap);
	Collider->OnComponentEndOverlap.AddDynamic(this, &ABaseEnemy::EndOverlap);
}


void ABaseEnemy::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult) 
{
	isColliding = true;

	if (OtherActor != nullptr)
	{
		ILifeManagerInterface* LifeManager = Cast<ILifeManagerInterface>(OtherActor);

		if (LifeManager)
		{
			LifeManager->Execute_ReduceAmount(OtherActor, NormalDamage);
		}

	}
}


void ABaseEnemy::EndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)

{
	isColliding = false;
}

void ABaseEnemy::DpsDamageFucnt() 
{
	ILifeManagerInterface* LifeManager = Cast<ILifeManagerInterface>(Target);

	if (LifeManager)
	{
		LifeManager->Execute_ReduceAmount(Target, DpsDamage);
		GetWorld()->GetTimerManager().SetTimer(delayTimerHandle, this, &ABaseEnemy::DpsDamageFucnt, 1.f, false);

	}

}
// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{

	if (isColliding) 
	{
		DpsDamageFucnt();
	}
}


