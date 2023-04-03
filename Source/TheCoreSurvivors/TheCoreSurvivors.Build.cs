// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TheCoreSurvivors : ModuleRules
{
	public TheCoreSurvivors(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
