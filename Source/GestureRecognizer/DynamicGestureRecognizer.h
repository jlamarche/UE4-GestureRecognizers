// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GestureRecognizerComponent.h"
#include "DynamicGestureRecognizer.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGestureMoved, UGestureRecognizerComponent *, Recognizer);

/**
 *  Base class for gesture recognizers that continually update their delegate during the gesture, rather than waiting for the gesture to be finished.
 */

UCLASS(ClassGroup=Input, meta=(BlueprintSpawnableComponent))
class  UDynamicGestureRecognizer : public UGestureRecognizerComponent
{
	GENERATED_BODY()
	
	
	/** Delegate function called for ongoing gestures. This value is used, for example, to repeatedly provide the current values of a pinch or rotate gesture */
	UPROPERTY(BlueprintAssignable, Category=Gestures)
	FGestureMoved GestureMovedDelegate;
	
};
