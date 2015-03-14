// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GestureMathLibrary.h"
#include "DynamicGestureRecognizer.h"
#include "PinchRotateGestureRecognizer.generated.h"

/**
 * Gesture recognizer for two-finger pinch and rotate gestures
 */
UCLASS(ClassGroup=Input, meta=(BlueprintSpawnableComponent))
class UPinchRotateGestureRecognizer : public UDynamicGestureRecognizer
{
	GENERATED_BODY()
	UPinchRotateGestureRecognizer();
	
public:
	
	/** The smallest change in angle (degrees) between two fingers before the gesture is recognized as rotating */
	UPROPERTY(EditAnywhere, Category=Gestures)
	float MinimumAngleChangeForRotate;
	
	/** The smallest change in distance (pixels) between two fingers before the gesture is recognized as a pinch */
	UPROPERTY(EditAnywhere, Category=Gestures)
	float MinimumDistanceChangeForPinch;
	
	/** The angle change since the last GestureMoved delegate call */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Gestures|Result")
	float DeltaRotationDegrees;
	
	/** The angle change (degrees) since the gesture started. Note, any time the number of fingers being used stops being two, that resets the accumulation. When you go back to two fingers, it's treated as a new gesture, even if all fingers haven't been taken off the device */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Gestures|Result")
	float AccumulatedAngleChange;
	
	/** The change in distance in pixels between the two touches since the last GestureMoved delegate call */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Gestures|Result")
	float DeltaDistancePixels;
	
	/** The total change in distance in pixels since the pinch started */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Gestures|Result")
	float AccumulatedDistanceChange;
	
	/** Whether a pinch has started. Delegate will only get notified if this or bIsRotating is true */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Gestures|Result")
	bool bIsPinching;
	
	/** Whether a rotate has started. Delegate will only get notified if this or bIsPinching are true */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Gestures|Result")
	bool bIsRotating;
	
	
protected:
	virtual void DetectGestures(float DeltaTime) override;
	virtual void GestureFinished() override;
	virtual void ResetGesture(void) override;
	
private:

};
