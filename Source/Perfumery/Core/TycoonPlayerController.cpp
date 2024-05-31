// © 2024 Alicia Schramek

#include "TycoonPlayerController.h"
#include "PlayerMoney/PlayerMoneyHandler.h"

void ATycoonPlayerController::BeginPlay()
{
    Super::BeginPlay();

    PlayerMoneyHandler = NewObject<UPlayerMoneyHandler>(this);
    if (PlayerMoneyHandler)
    {
        PlayerMoneyHandler->Initialize(GetWorld());
    }
}