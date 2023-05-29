// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IExpManagerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIExpManagerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class THECORESURVIVORS_API IIExpManagerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent,Category = "Experience")
	void AddXP(float experience);

};
