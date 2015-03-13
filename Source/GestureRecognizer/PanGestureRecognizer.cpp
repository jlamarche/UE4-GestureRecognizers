#include "GestureRecognizer.h"
#include "PanGestureRecognizer.h"

UPanGestureRecognizer::UPanGestureRecognizer() 	: Super()
, MinimumTouchCount(1)
, MaximumTouchCount(10)
, bGestureBegan(false)
{
	
}

void UPanGestureRecognizer::DetectGestures(float DeltaTime)
{
	if (CurrentTouchCount >= MinimumTouchCount && CurrentTouchCount <= MaximumTouchCount)
	{
		bGestureBegan = true;
		for (int32 Index = 0; Index < EKeys::NUM_TOUCH_KEYS; Index++)
		{
			if (Index < CurrentTouchCount)
			{
				TouchPoints[Index] = TouchData[Index].TouchPoints.Last();
			}
			else
			{
				TouchPoints[Index] = FVector2D(FLT_MAX, FLT_MAX);
			}
		}
		GestureMovedDelegate.Broadcast(this);
	}
}

void UPanGestureRecognizer::GestureFinished()
{
	if (bGestureBegan)
	{
		GestureEndedDelegate.Broadcast(this);
	}
}

void UPanGestureRecognizer::ResetGesture()
{
	Super::ResetGesture();
	bGestureBegan = false;
}
int32 UPanGestureRecognizer::GetTouchCount()
{
	return CurrentTouchCount;
}