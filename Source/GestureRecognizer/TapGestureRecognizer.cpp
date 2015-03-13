// Fill out your copyright notice in the Description page of Project Settings.

#include "GestureRecognizer.h"
#include "TapGestureRecognizer.h"


UTapGestureRecognizer::UTapGestureRecognizer() 	: Super()
, MinimumTimeForTap(0.f)
, MaximumTimeForTap(0.2f)
, MinimumTouchCount(1)
, MaximumTouchCount(1)
, MinimumNumberOfTaps(1)
, MaximumTimeBetweenTaps(.1f)
, NumberOfFingersInTap(0)
, LastTapTime(0.f)
, TapCount(0)
{

}

// Called when the game starts
void UTapGestureRecognizer::InitializeComponent()
{
	Super::InitializeComponent();

}

void UTapGestureRecognizer::DetectGestures(float DeltaTime)
{
	float Now = GetWorld()->GetRealTimeSeconds();
	
	if ( (Now > LastTapTime + MaximumTimeBetweenTaps) && (TapCount > 0) && CurrentTouchCount == 0)
	{
		NumberOfTaps = TapCount;
		GestureEndedDelegate.Broadcast(this);
		TapCount = 0;
		NumberOfFingersInTap = 0;
		LastTapTime = 0.f;
		NumberOfTaps = 0;
	}
}

void UTapGestureRecognizer::GestureFinished()
{
	float gestureTime = LastFingerTouchTime - FirstFingerTouchTime;
	if (gestureTime >= MinimumTimeForTap && gestureTime <= MaximumTimeForTap)
	{
		if (MaxFingersThisGesture >= MinimumTouchCount && MaxFingersThisGesture <= MaximumTouchCount)
		{
			// More than a tiny bit of movement and it's not a tap.
			if (TouchData[0].GestureLength() > 5.f)
			{
				return;
			}
			
			if (MaxFingersThisGesture > NumberOfFingersInTap)
				NumberOfFingersInTap = MaxFingersThisGesture;
			
			TapCount++;
			
			// We don't call delegate right away - wait to see if it's a multi-tap
			LastTapTime = GetWorld()->GetRealTimeSeconds();
		}
	}
}

void UTapGestureRecognizer::ResetGesture()
{
	Super::ResetGesture();
}