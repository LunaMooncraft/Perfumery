// © 2024 Alicia Schramek

#include "PlayerMoneyHandler.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "GameHelper.h" 

UPlayerMoneyHandler::UPlayerMoneyHandler()
{
    PlayerMoneyWidgetClass = UGameHelper::FindWidgetClass(TEXT("/Game/UI/WBP_PlayerMoney.WBP_PlayerMoney_C"));
}

void UPlayerMoneyHandler::Initialize(UWorld* World)
{
    if (PlayerMoneyWidgetClass)
    {
        PlayerMoneyWidgetInstance = UGameHelper::AddWidgetToViewport(World->GetFirstPlayerController(), PlayerMoneyWidgetClass);
    }
}