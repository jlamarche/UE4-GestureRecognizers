// =================================================================================================
//
//       ^                     ____________________
//      / \                   |                   |
//     / _ \                  | MartianCraft      |
//    ( (_) )                 | Public Code       |
//   /|  |  |\                |___________________|
//  //|__|__|\\
// (/   (|)   \)
//      \ /
//       v
//
//    Copyright 2015 MartianCraft. All rights reserved.
//    http://www.martiancraft.com       jeff@martiancraft.com
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//	THE SOFTWARE.
//
// =================================================================================================
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
	
	/** The minimum number of fingers that must be touching the screen in order for the delegate to be notified */
	UPROPERTY(EditAnywhere, Category=Gestures)
	int32 MinimumTouchCount;
	
	/** The maximum number of fingers that can be down for the delegate to be notified */
	UPROPERTY(EditAnywhere, Category=Gestures)
	int32 MaximumTouchCount;
	
	/** Access to the position of each key for the delegate method */
	UPROPERTY(EditAnywhere, Category="Gestures|Result")
	FVector2D TouchPoints[EKeys::NUM_TOUCH_KEYS];
	
	/** Allows delegate access to the number of fingers currently touching the screen */
	UFUNCTION(BlueprintCallable, Category="Gestures|Result")
	int32 GetTouchCount();
	
	
	
protected:
	virtual void DetectGestures(float DeltaTime) override;
	virtual void GestureFinished() override;
	virtual void ResetGesture(void) override;
	
private:
	bool bGestureBegan;
	
};
