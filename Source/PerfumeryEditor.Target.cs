// © 2024 Alicia Schramek

using UnrealBuildTool;
using System.Collections.Generic;

public class PerfumeryEditorTarget : TargetRules
{
	public PerfumeryEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Perfumery" } );
	}
}
