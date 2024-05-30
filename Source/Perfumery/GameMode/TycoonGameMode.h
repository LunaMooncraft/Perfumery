// © 2024 Alicia Schramek

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "IngredientStruct.h"
#include "PerfumeStruct.h"
#include "TycoonGameMode.generated.h"

UCLASS()
class PERFUMERY_API ATycoonGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
    ATycoonGameMode();

    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data")
    UDataTable* IngredientDataTable;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data")
    UDataTable* PerfumeDataTable;
};
