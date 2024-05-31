// © 2024 Alicia Schramek

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TycoonPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PERFUMERY_API ATycoonPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
    ATycoonPlayerController();

	virtual void BeginPlay() override;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
    TSubclassOf<class UUserWidget> PlayerMoneyWidgetClass;

    // Pointer to the actual widget instance
    UUserWidget* PlayerMoneyWidgetInstance;
};
