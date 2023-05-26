// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LifeManagerInterface.h"
#include "Components/ActorComponent.h"
#include "LifeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THECORESURVIVORS_API ULifeComponent : public UActorComponent,public ILifeManagerInterface
{
	GENERATED_BODY()

	DECLARE_DELEGATE(FKillEntity);

	
	UPROPERTY(BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	bool IsDamageOverTime = false;
	UPROPERTY(BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	int DamagePerSecond = 0;

public:	
	// Sets default values for this component's properties
	ULifeComponent();

	UPROPERTY(BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float MaxLife = 100;

	UPROPERTY(BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float CurrentLife = MaxLife;

	//LifeComponent
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent, Category = "Damage")
	void ReduceAmount(float damage); virtual void ReduceAmount_Implementation(float damage) override;

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "Damage")
	void RestoreAmount(float recover); virtual void RestoreAmount_Implementation(float recover) override;
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "Damage")
	void StartDamageOverTime(float dps); virtual void StartDamageOverTime_Implementation(float dps) override;

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "Damage")
	void StopDamageOverTime(); virtual void StopDamageOverTime_Implementation() override;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FKillEntity OnKillEntity;
		
};
