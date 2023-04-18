
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BEAIController.h"
#include "Kismet/GameplayStatics.h"
#include "../LifeComponent.h"
#include "../LifeManagerInterface.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "BaseEnemy.generated.h"

UCLASS()
class THECORESURVIVORS_API ABaseEnemy : public APawn
{
	GENERATED_BODY()
	
public:	
	
	// Sets default values for this actor's properties
	ABaseEnemy();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "BaseEnemy")
		class AActor* Target;

	UFUNCTION()
	void BeginOverlap(class UPrimitiveComponent* overlappedComponent, class AActor* otherActor,class UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep,const FHitResult& sweepResult);
	
	UFUNCTION()
	void EndOverlap(class UPrimitiveComponent* overlappedComponent, class AActor* otherActor, class UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

	ULifeComponent* _LifeComponent = nullptr;
	UFloatingPawnMovement* MovementComponent = nullptr;
	
protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseEnemy")
		class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseEnemy")
		class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseEnemy")
		class UBoxComponent* Collider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseEnemy")
		float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseEnemy")
		float TotalLife;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseEnemy")
		bool isColliding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseEnemy")
		int NormalDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseEnemy")
		int DpsDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseEnemy")
		int RatioToAppear;
	
	// For Debug
	FVector Direction; 

	float TotalDistance;
	float CurrentDistance;
	FVector StartLocation;

};
