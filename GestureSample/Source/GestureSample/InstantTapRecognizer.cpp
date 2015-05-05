// 2014 MartianCraft, LLC, See eader file for license & copyright notice

#include "GestureSample.h"
#include "InstantTapRecognizer.h"



void UInstantTapRecognizer::TouchBegan(int32 FingerIndex, FVector2D Position)
{
	WhichFinger = FingerIndex;
	TouchLocation = Position;
	GestureStartedDelegate.Broadcast(this, GetWorld()->GetDeltaSeconds());
}

void UInstantTapRecognizer::TouchEnded(int32 FingerIndex)
{
	WhichFinger = FingerIndex;
	TouchLocation = TouchData[FingerIndex].TouchPoints.Last();
	GestureEndedDelegate.Broadcast(this, GetWorld()->GetDeltaSeconds());
}