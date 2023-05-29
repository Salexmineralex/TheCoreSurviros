
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BEAIController.h"
#include "Kismet/GameplayStatics.h"
#include "../LifeComponent.h"
#include "../LifeManagerInterface.h"
#include "BEAIController.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "TimerManager.h"
#include "TheCoreSurvivors/ExperienceItem.h"
#include "TheCoreSurvivors/FirstAidKitItem.h"
#include "BaseEnemy.generated.h"

UCLASS()
class THECORESURVIVORS_API ABaseEnemy : public APawn, public ILifeManagerInterface
{
	GENERATED_BODY()
	
public:	
	
	// Sets default values for this actor's properties
	ABaseEnemy();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "BaseEnemy")
		class AActor* Target;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AExperienceItem> ExperienceItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AFirstAidKitItem> AidKitItem;

	UFUNCTION()
	void BeginOverlap(class UPrimitiveComponent* overlappedComponent, class AActor* otherActor,class UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep,const FHitResult& sweepResult);
	
	UFUNCTION()
	void EndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void DpsDamageFucnt();

	UFUNCTION()
	void Die();
	
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


	FTimerHandle delayTimerHandle;
	//LifeInterface
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent, Category = "Damage")
	void ReduceAmount(float damage); virtual void ReduceAmount_Implementation(float damage) override;

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "Damage")
	void RestoreAmount(float recover); virtual void RestoreAmount_Implementation(float recover) override;
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "Damage")
	void StartDamageOverTime(float dps); virtual void StartDamageOverTime_Implementation(float dps) override;

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "Damage")
	void StopDamageOverTime(); virtual void StopDamageOverTime_Implementation() override ;



};
