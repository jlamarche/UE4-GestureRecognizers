// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "GestureRecognizer.h"
#include "GestureRecognizerGameMode.h"
#include "GestureRecognizerHUD.h"
#include "GestureRecognizerCharacter.h"

AGestureRecognizerGameMode::AGestureRecognizerGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGestureRecognizerHUD::StaticClass();
}
