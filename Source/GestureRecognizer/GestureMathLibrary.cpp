// Fill out your copyright notice in the Description page of Project Settings.

#include "GestureRecognizer.h"
#include "GestureMathLibrary.h"




float UGestureMathLibrary::AngleBetweenLinesRadians(const FVector2D& Line1Start, const FVector2D& Line1End, const FVector2D& Line2Start, const FVector2D& Line2End)
{
	float A = Line1End.X - Line1Start.X;
	float B = Line1End.Y - Line1Start.Y;
	float C = Line2End.X - Line2Start.X;
	float D = Line2End.Y - Line2Start.Y;
	
	float Radians = acos(((A * C) + (B * D)) / ((sqrtf(A * A + B * B)) * (sqrtf(C * C + D * D))));
	return Radians;
}

float UGestureMathLibrary::AngleBetweenLinesDegrees(const FVector2D& Line1Start, const FVector2D& Line1End, const FVector2D& Line2Start, const FVector2D& Line2End)
{
	return FMath::RadiansToDegrees(AngleBetweenLinesRadians(Line1Start, Line1End, Line2Start, Line2End));
}