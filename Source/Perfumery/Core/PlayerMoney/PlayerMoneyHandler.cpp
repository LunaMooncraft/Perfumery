// © 2024 Alicia Schramek

#include "PlayerMoneyHandler.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

UPlayerMoneyHandler::UPlayerMoneyHandler()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> PlayerMoneyWidgetFinder(TEXT("/Game/UI/WBP_PlayerMoney.WBP_PlayerMoney_C"));
    if (PlayerMoneyWidgetFinder.Succeeded())
    {
        PlayerMoneyWidgetClass = PlayerMoneyWidgetFinder.Class;
    }
}

void UPlayerMoneyHandler::Initialize(UWorld* World)
{
    if (PlayerMoneyWidgetClass)
    {
        PlayerMoneyWidgetInstance = CreateWidget<UUserWidget>(World, PlayerMoneyWidgetClass);
        if (PlayerMoneyWidgetInstance != nullptr)
        {
            PlayerMoneyWidgetInstance->AddToViewport();
        }
    }
}