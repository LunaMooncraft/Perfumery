// © 2024 Alicia Schramek

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerInventoryHandler.generated.h"

UCLASS()
class PERFUMERY_API UPlayerInventoryHandler : public UObject
{
    GENERATED_BODY()

public:
    UPlayerInventoryHandler();
    
    void Initialize(UWorld* World);

private:
    UPROPERTY()
    UUserWidget* PlayerInventoryWidgetInstance;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UUserWidget> PlayerInventoryWidgetClass;
};