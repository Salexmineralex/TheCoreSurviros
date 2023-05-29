
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.h"
#include "ExperienceItem.generated.h"

UCLASS()
class THECORESURVIVORS_API AExperienceItem : public AItem
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExperienceItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float experiencedGained;

	void Init(float newValue);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
