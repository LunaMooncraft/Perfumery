// © 2024 Alicia Schramek

#include "TycoonPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

ATycoonPlayerController::ATycoonPlayerController()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> WidgetFinder(TEXT("/Game/Widgets/WBP_PlayerMoney.WBP_PlayerMoney_C"));
    if (WidgetFinder.Succeeded())
    {
        PlayerMoneyWidgetClass = WidgetFinder.Class;
    }
}

void ATycoonPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (PlayerMoneyWidgetClass != nullptr)
    {
        UUserWidget* WidgetInstance = CreateWidget<UUserWidget>(GetWorld(), PlayerMoneyWidgetClass);
        if (WidgetInstance != nullptr)
        {
            WidgetInstance->AddToViewport();
        }
    }
}

