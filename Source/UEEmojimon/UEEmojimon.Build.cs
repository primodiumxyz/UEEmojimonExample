// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEEmojimon : ModuleRules
{
	public UEEmojimon(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" ,"UEMUD", "ContextFramework", "TurboLinkGrpc", "UMG","web3Unreal"});

		PrivateDependencyModuleNames.AddRange(new string[] { "UEMUD" ,"ContextFramework", "TurboLinkGrpc", "StructUtils", "DeveloperSettings", "UMG","web3Unreal"});

	}
}
