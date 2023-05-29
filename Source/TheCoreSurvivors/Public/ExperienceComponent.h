// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IExpManagerInterface.h"
#include "Components/ActorComponent.h"
#include "ExperienceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THECORESURVIVORS_API UExperienceComponent : public UActorComponent, public IIExpManagerInterface
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_DELEGATE(FLevelUp);

public:	
	// Sets default values for this component's properties
	UExperienceComponent();

	
	UPROPERTY(BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float MaxXP = 100;

	UPROPERTY(BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float CurrentXP = 0;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	virtual void AddXP_Implementation(float experience) override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FLevelUp OnLevelUP;
		
};
