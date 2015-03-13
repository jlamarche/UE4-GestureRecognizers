// 2014 MartianCraft, LLC

#pragma once

#include "Components/ActorComponent.h"
#include "GestureRecognizerComponent.generated.h"


USTRUCT()
struct FGestureTouchData
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY()
	TArray<FVector2D> TouchPoints;

	// The time of the first detected touch of this gesture
	UPROPERTY()
	float FirstTouchTime;
	
	// The time of the most recent detected touch of this gesture
	UPROPERTY()
	float LatestTouchTime;
	
	// Returns true if the finger associated with this touch has lifted from the screen
	UPROPERTY()
	bool bIsTouchEnded;
	
	UPROPERTY()
	bool bIsTouchStarted;
	
	// Straight line distance from start to end of this gesture
	float GestureLength()
	{
		FVector2D StartPosition = TouchPoints[0];
		FVector2D EndPosition = TouchPoints.Last();
		
		float Distance = (EndPosition - StartPosition).Size();
		return Distance;
	};
	
	float ElapsedTime()
	{
		return LatestTouchTime - FirstTouchTime;
	};
	
	// Actual length of the gesture path
	float PixelsTraveled()
	{
		float DistanceTraveled = 0.f;
		
		for (int32 Index = 0; Index < TouchPoints.Num() - 1; Index++)
		{
			FVector2D CurrentPoint = TouchPoints[Index];
			FVector2D NextPoint = TouchPoints[Index+1];
			DistanceTraveled += (NextPoint - CurrentPoint).Size();
		}
		return DistanceTraveled;
	}
	
	float XDifference()
	{
		FVector2D StartPosition = TouchPoints[0];
		FVector2D EndPosition = TouchPoints.Last();
		
		return EndPosition.X - StartPosition.X;
	}
	
	float XDistance()
	{
		return fabsf(XDifference());
	}
	
	float YDifference()
	{
		FVector2D StartPosition = TouchPoints[0];
		FVector2D EndPosition = TouchPoints.Last();
		
		return EndPosition.Y - StartPosition.Y;
	}
	
	float YDistance()
	{
		return fabsf(YDifference());
	}
	
};
class UGestureRecognizerComponent;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGestureEnded, UGestureRecognizerComponent *, Recognizer);


/** Base class for gesture recognizer components. This class doesn't recognize any gestures, it simply provides a base class that concrete gesture recognizers can use */

UCLASS(ClassGroup=Input, meta=(BlueprintSpawnableComponent))
class UGestureRecognizerComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UGestureRecognizerComponent();
	virtual void InitializeComponent() override;
	virtual void ReceiveTick(float DeltaTime) override;
	
	// ===========================================================================
	// Delegates
	
	/** Delegate function called when a gesture is completed. For simple gestures, like swipes and taps, this is the only delegate function that will get called. For ongoing gestures, this will indicate that the gesture has ended and no more FGestureMoved calls will happen until the next gesture starts.
	 */
	UPROPERTY(BlueprintAssignable, Category=Gestures)
	FGestureEnded GestureEndedDelegate;
	

	// ===========================================================================
	// Gesture detection
	
	UFUNCTION(BlueprintCallable, Category="Gestures|Detection")
	/** Subclasses should override this to detect gestures that require tick-level precision **/
	virtual void DetectGestures(float DeltaTime);
	
	/** Called when the last finger of a gesture is lifted off of the screen. Good class to override for simle gesture detection */
	virtual void GestureFinished();
	
	/** Called when a finger touches down for the first time during a gesture */
	virtual void TouchBegan(int32 FingerIndex, FVector2D Position);
	
	/** Called while a finger is touching the screen */
	virtual void TouchMoved(int32 FingerIndex, FVector2D Position);
	
	/** Called when a finger is lifted from the screen */
	virtual void TouchEnded(int32 FingerIndex);

	// ===========================================================================
	int32 FORCEINLINE GetCurrentTouchCount() {return CurrentTouchCount;};
	int32 FORCEINLINE GetPreviousTouchCount() {return PreviousTouchCount;};
	int32 FORCEINLINE GetMaxFingersThisGesture() {return MaxFingersThisGesture;};
	
protected:
	
	// This stores information about each of the possible touches.
	FGestureTouchData TouchData[EKeys::NUM_TOUCH_KEYS];
	int32 CurrentTouchCount;
	int32 PreviousTouchCount;
	UPlayerInput *PlayerInput;
	int32 MaxFingersThisGesture;
	float FirstFingerTouchTime;
	float LastFingerTouchTime;
	
	virtual void ResetGesture(void);
	
private:
	void CalculateTouchCount(const FVector (&Touches)[EKeys::NUM_TOUCH_KEYS]);
	void UpdateStoredTouchData(const FVector (&Touches)[EKeys::NUM_TOUCH_KEYS]);
	void ProcessTouches(const FVector (&Touches)[EKeys::NUM_TOUCH_KEYS], float DeltaTime);

};
