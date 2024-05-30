// © 2024 Alicia Schramek

using UnrealBuildTool;
using System.Collections.Generic;

public class PerfumeryTarget : TargetRules
{
	public PerfumeryTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Perfumery" } );
	}
}
