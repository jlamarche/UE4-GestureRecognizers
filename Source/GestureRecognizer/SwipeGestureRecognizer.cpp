// Fill out your copyright notice in the Description page of Project Settings.

#include "GestureRecognizer.h"
#include "SwipeGestureRecognizer.h"

USwipeGestureRecognizer::USwipeGestureRecognizer() 	: Super()
{
	MinimumSwipeDistance = 50.f;
	Tolerance = 20.f;
	MaximumGestureDuration = .25f;
	MaximumTouches = 1;
	MinimumTouches = 1;
}

void USwipeGestureRecognizer::GestureFinished()
{
	if (MaxFingersThisGesture < MinimumTouches || MaxFingersThisGesture > MaximumTouches)
	{
		return;
	}
	
	if (TouchData[0].GestureLength() < MinimumSwipeDistance)
	{
		return;
	}
	
	if (TouchData[0].ElapsedTime() > MaximumGestureDuration)
	{
		return;
	}
	
	FVector2D StartPoint = TouchData[0].TouchPoints[0];
	FVector2D EndPoint = TouchData[0].TouchPoints.Last();
	float XDistance = TouchData[0].XDistance();
	float YDistance = TouchData[0].YDistance();
	float YDifference = TouchData[0].YDifference();
	float XDifference = TouchData[0].XDifference();
	const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
	
	float HorizontalEdgeTolerance = .1f * ViewportSize.X;
	float VerticalEdgeTolerance = .1f * ViewportSize.Y;
	
	// Horizontal Swipes
	if (XDistance >= MinimumSwipeDistance && YDistance < Tolerance)
	{
		// @TODO: Swipe from edges need a tolerance value, probably based on percentage of screen size.
		// Swipe from Left Edge
		if (StartPoint.X <= HorizontalEdgeTolerance && XDifference > 0.f)
		{
			if (SupportedSwipes.bSupportsSwipeFromLeftEdge)
			{
				SwipeType = ESwipeType::SwipeFromLeftEdge;
				GestureEndedDelegate.Broadcast(this);
			}
		}
		// Swipe Right
		else if (XDifference > 0.f)
		{
			if (SupportedSwipes.bSupportsSwipeRight)
			{
				SwipeType = ESwipeType::SwipeRight;
				GestureEndedDelegate.Broadcast(this);
			}
		}
		// Swipe from Right Edge
		else if (StartPoint.X >= (ViewportSize.X - HorizontalEdgeTolerance))
		{
			if (SupportedSwipes.bSupportsSwipeFromRightEdge)
			{
				SwipeType = ESwipeType::SwipeFromRightEdge;
				GestureEndedDelegate.Broadcast(this);
			}
		}
		// Swipe Left
		else
		{
			if (SupportedSwipes.bSupportsSwipeLeft)
			{
				SwipeType = ESwipeType::SwipeLeft;
				GestureEndedDelegate.Broadcast(this);
			}
		}
	}
	// Vertical Swipes
	else if (YDistance >= MinimumSwipeDistance && XDistance < Tolerance)
	{
		// Swipe from Top Edge
		if (StartPoint.Y <= VerticalEdgeTolerance && YDifference > 0.f)
		{
			if (SupportedSwipes.bSupportsSwipeFromTopEdge)
			{
				SwipeType = ESwipeType::SwipeFromTopEdge;
				GestureEndedDelegate.Broadcast(this);
			}
		}
		// Swipe Up
		else if (YDifference > 0.f)
		{
			if (SupportedSwipes.bSupportsSwipeUp)
			{
				SwipeType = ESwipeType::SwipeDown;
				GestureEndedDelegate.Broadcast(this);
			}
		}
		// Swipe from Bottom
		else if (StartPoint.Y > (ViewportSize.Y - VerticalEdgeTolerance))
		{
			if (SupportedSwipes.bSupportsSwipeFromBottomEdge)
			{
				SwipeType = ESwipeType::SwipeFromBottomEdge;
				GestureEndedDelegate.Broadcast(this);
			}
		}
		// Swipe Up
		else
		{
			if (SupportedSwipes.bSupportsSwipeDown)
			{
				SwipeType = ESwipeType::SwipeUp;
				GestureEndedDelegate.Broadcast(this);
			}
		}
	}
	// Diagonal Swipes
	else if (YDistance >= MinimumSwipeDistance && XDistance >= MinimumSwipeDistance)
	{
		// Up and Right
		if (YDifference < 0.f && XDifference > 0.f)
		{
			if (SupportedSwipes.bSupportsSwipeDiagonalUpRight)
			{
				SwipeType = ESwipeType::SwipeUpRight;
				GestureEndedDelegate.Broadcast(this);
			}
		}
		// Up and Left
		else if (YDifference < 0.f && XDifference < 0.f)
		{
			if (SupportedSwipes.bSupportsSwipeDiagonalUpLeft)
			{
				SwipeType = ESwipeType::SwipeUpLeft;
				GestureEndedDelegate.Broadcast(this);
			}
		}
		// Down and Right
		else if (YDifference > 0.f && XDifference > 0.f)
		{
			if (SupportedSwipes.bSupportsSwipeDiagonalDownRight)
			{
				SwipeType = ESwipeType::SwipeDownRight;
				GestureEndedDelegate.Broadcast(this);
			}
		}
		// Down and Left
		else
		{
			if (SupportedSwipes.bSupportsSwipeDiagonalDownLeft)
			{
				SwipeType = ESwipeType::SwipeDownLeft;
				GestureEndedDelegate.Broadcast(this);
			}
		}
	}
}

ESwipeType USwipeGestureRecognizer::GetSwipeType()
{
	return SwipeType;
}
