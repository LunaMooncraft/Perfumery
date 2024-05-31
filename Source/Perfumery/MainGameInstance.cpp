// © 2024 Alicia Schramek

#include "MainGameInstance.h"
#include "Blueprint/UserWidget.h"

UMainGameInstance::UMainGameInstance() : PlayerMoney(250.0f)
{
    InventoryComponent = CreateDefaultSubobject<UPlayerInventoryComponent>(TEXT("InventoryComponent"));
}

UPlayerInventoryComponent* UMainGameInstance::GetInventoryComponent() const
{
    return InventoryComponent;
}


float UMainGameInstance::GetPlayerMoney() const
{
    return PlayerMoney;
}