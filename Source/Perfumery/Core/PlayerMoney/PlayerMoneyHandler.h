// © 2024 Alicia Schramek

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerMoneyHandler.generated.h"

UCLASS()
class PERFUMERY_API UPlayerMoneyHandler : public UObject
{
    GENERATED_BODY()

public:
    UPlayerMoneyHandler();
    
    void Initialize(UWorld* World);

private:
    UPROPERTY()
    UUserWidget* PlayerMoneyWidgetInstance;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UUserWidget> PlayerMoneyWidgetClass;
};