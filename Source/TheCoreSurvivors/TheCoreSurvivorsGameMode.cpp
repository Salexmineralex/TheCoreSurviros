// Copyright Epic Games, Inc. All Rights Reserved.

#include "TheCoreSurvivorsGameMode.h"
#include "TheCoreSurvivorsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATheCoreSurvivorsGameMode::ATheCoreSurvivorsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
