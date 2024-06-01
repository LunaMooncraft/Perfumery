// © 2024 Alicia Schramek

#include "TycoonPlayerController.h"
#include "PlayerMoney/PlayerMoneyHandler.h"
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
}