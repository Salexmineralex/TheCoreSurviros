// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BEAIController.h"
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
	float GetMovementSpeed() { return MovementSpeed; }

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

	// For Debug
	FVector Direction; 

	float TotalDistance;
	float CurrentDistance;
	FVector StartLocation;

};
