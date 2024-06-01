// © 2024 Alicia Schramek

#include "TycoonPlayerController.h"
#include "PlayerMoney/PlayerMoneyHandler.h"
#include "PlayerInventoryHandler.h"
#include "GameHelper.h"
#include "Blueprint/UserWidget.h"
#include "InputMappingContext.h"

void ATycoonPlayerController::BeginPlay()
{
    Super::BeginPlay();

    PlayerMoneyHandler = NewObject<UPlayerMoneyHandler>(this);
    if (PlayerMoneyHandler)
    {
        PlayerMoneyHandler->Initialize(GetWorld());
    }

    PlayerInventoryHandler = NewObject<UPlayerInventoryHandler>(this);
    if (PlayerInventoryHandler)
    {
        PlayerInventoryHandler->Initialize(GetWorld());
    }
}