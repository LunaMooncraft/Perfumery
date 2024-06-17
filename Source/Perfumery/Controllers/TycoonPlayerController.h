// © 2024 Alicia Schramek

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TycoonPlayerController.generated.h"

UCLASS()
class PERFUMERY_API ATycoonPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
};
