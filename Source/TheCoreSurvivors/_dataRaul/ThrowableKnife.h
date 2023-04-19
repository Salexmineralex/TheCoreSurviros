// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ThrowableKnife.generated.h"

UCLASS()
class THECORESURVIVORS_API AThrowableKnife : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AThrowableKnife();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* staticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* boxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UProjectileMovementComponent* projectileMovement;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* root;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float damage = 50;

	UFUNCTION()
	void BeginOverlap(class UPrimitiveComponent* overlappedComponent, class AActor* otherActor,class UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep,const FHitResult& sweepResult);
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

