// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GestureRecognizer : ModuleRules
{
	public GestureRecognizer(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "AIModule" });
		PrivateDependencyModuleNames.AddRange(new string[] { "RenderCore" });
	}
}
