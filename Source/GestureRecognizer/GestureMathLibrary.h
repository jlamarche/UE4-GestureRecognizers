// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GestureMathLibrary.generated.h"

/**
 * 
 */
UCLASS()
class  UGestureMathLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	
	
public:
	/**
	 * Calculates the angle between two lines in 2D space in radians
	 *
	 * @param	Line1Start	- The start point of the first line
	 * @param	Line1End - The end point of the first line
	 * @param	Line2Start - The start point of the second line
	 * @param	Line2End - The end point of the second line
	 * @result	The angle between the two lines in Radians
	 */
	UFUNCTION(BlueprintPure, Category="Math|Gesture Utils")
	static float AngleBetweenLinesRadians(const FVector2D& Line1Start, const FVector2D& Line1End, const FVector2D& Line2Start, const FVector2D& Line2End);
	
	/**
	 * Calculates the angle between two lines in 2D space in degrees
	 *
	 * @param	Line1Start	- The start point of the first line
	 * @param	Line1End - The end point of the first line
	 * @param	Line2Start - The start point of the second line
	 * @param	Line2End - The end point of the second line
	 * @result	The angle between the two lines.
	 */
	UFUNCTION(BlueprintPure, Category="Math|Gesture Utils")
	static float AngleBetweenLinesDegrees(const FVector2D& Line1Start, const FVector2D& Line1End, const FVector2D& Line2Start, const FVector2D& Line2End);
};
