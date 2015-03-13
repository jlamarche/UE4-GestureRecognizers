// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GestureRecognizerComponent.h"
#include "TapGestureRecognizer.generated.h"

/**
 * Recognizes tap gestures, including multi-tap (double tap, triple tap) gestures and multiple-touch taps (two-finger taps).
 */
UCLASS(ClassGroup=Input, meta=(BlueprintSpawnableComponent))
class UTapGestureRecognizer : public UGestureRecognizerComponent
{
	GENERATED_BODY()
	
public:
	UTapGestureRecognizer();
	
	/** Minimum amount of time (in seconds) that the finger can be on the screen to trigger this gesture. Typically 0.0, but can be longer if a long-tap is desired */
	UPROPERTY(EditAnywhere, Category=Gestures)
	float MinimumTimeForTap;
	
	/** The maximum amount of time the finger can stay on the screen for it to count as a tap. */
	UPROPERTY(EditAnywhere, Category=Gestures)
	float MaximumTimeForTap;
	
	/** The minimum number of fingers that must have been used to register as a tap */
	UPROPERTY(EditAnywhere, Category=Gestures)
	int32 MinimumTouchCount;
	
	/** The maximum number of fingers that must have been used to register as a tap */
	UPROPERTY(EditAnywhere, Category=Gestures)
	int32 MaximumTouchCount;
	
	/** If checking for multiple taps (double-tap, triple-tap), set this value to a value higher than one */
	UPROPERTY(EditAnywhere, Category=Gestures)
	int32 MinimumNumberOfTaps;
	
	/** The maximum multiple tap (double, triple) that this recognizer will recognize. */
	UPROPERTY(EditAnywhere, Category=Gestures)
	int32 MaximumNumberOfTaps;

	/** If looking for multi-taps, the maximum amount of time that can elapse from the start of one tap until the start of the next tap for them to be considered a single gesture **/
	UPROPERTY(EditAnywhere, Category=Gestures)
	float MaximumTimeBetweenTaps;
	
	UPROPERTY(BlueprintReadWrite, Category="Gestures|Result")
	int32 NumberOfFingersInTap;
	
	UPROPERTY(BlueprintReadWrite, Category="Gestures|Result")
	int32 NumberOfTaps;
	
protected:
	virtual void InitializeComponent() override;
	virtual void DetectGestures(float DeltaTime) override;
	virtual void GestureFinished() override;
	virtual void ResetGesture(void) override;
	
	float LastTapTime;
	int32 TapCount;
};
