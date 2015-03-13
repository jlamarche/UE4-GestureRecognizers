// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DynamicGestureRecognizer.h"
#include "PanGestureRecognizer.generated.h"

/**
 *  Recognizes pan gestures - one or more fingers moving around the screen
 */
UCLASS(ClassGroup=Input, meta=(BlueprintSpawnableComponent))
class GESTURERECOGNIZER_API UPanGestureRecognizer : public UDynamicGestureRecognizer
{
	GENERATED_BODY()
	UPanGestureRecognizer();
	
protected:
	virtual void DetectGestures(float DeltaTime) override;
	virtual void GestureFinished() override;
	virtual void ResetGesture(void) override;
	
};
