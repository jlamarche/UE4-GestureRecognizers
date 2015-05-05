// 2014 MartianCraft, LLC, See eader file for license & copyright notice

#include "%%%PROJECTHEADER%%%"
#include "GestureMathLibrary.h"

float UGestureMathLibrary::AngleBetweenLines(const FVector2D& Line1Start, const FVector2D& Line1End, const FVector2D& Line2Start, const FVector2D& Line2End)
{
	float A = Line1End.X - Line1Start.X;
	float B = Line1End.Y - Line1Start.Y;
	float C = Line2End.X - Line2Start.X;
	float D = Line2End.Y - Line2Start.Y;
	
	float Line1Slope = ((Line1End.X - Line1Start.X) == 0.f) ? 0.f : (Line1End.Y - Line1Start.Y) / (Line1End.X - Line1Start.X);
	float Line2Slope = ((Line2End.X - Line2Start.X) == 0.f) ? 0.f : (Line2End.Y - Line2Start.Y) / (Line2End.X - Line2Start.X);
	
	float Angle = acosf(((A * C) + (B * D)) / ((sqrtf(A * A + B * B)) * (sqrtf(C * C + D * D))));
	
	if (Angle == 0.f) return 0.f;
	
	if (isnan(Angle) || isnan(-Angle))
		return 0.f;
	
	
	return (Line2Slope > Line1Slope) ? Angle : -Angle;
	
}