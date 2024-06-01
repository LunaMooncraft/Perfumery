// © 2024 Alicia Schramek

#include "PlayerInventoryHandler.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "GameHelper.h" 

UPlayerInventoryHandler::UPlayerInventoryHandler()
{
    PlayerInventoryWidgetClass = UGameHelper::FindWidgetClass(TEXT("/Game/UI/WBP_PlayerInventory.WBP_PlayerInventory_C"));
}

void UPlayerInventoryHandler::Initialize(UWorld* World)
{
    if (PlayerInventoryWidgetClass)
    {
        PlayerInventoryWidgetInstance = UGameHelper::AddWidgetToViewport(World->GetFirstPlayerController(), PlayerInventoryWidgetClass);
    }
}