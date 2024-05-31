// © 2024 Alicia Schramek

#include "PlayerInventoryComponent.h"
#include "PlayerInventoryItemStruct.h"

UPlayerInventoryComponent::UPlayerInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UPlayerInventoryComponent::AddItem(const FPlayerInventoryItemStruct& Item)
{
    // Check if the item already exists in the inventory
    for (FPlayerInventoryItemStruct& ExistingItem : InventoryItems)
    {
        if (ExistingItem.ID == Item.ID)
        {
            ExistingItem.Quantity += Item.Quantity;
            return;
        }
    }

    // If not, add the new item
    InventoryItems.Add(Item);
}

void UPlayerInventoryComponent::RemoveItem(int32 ID)
{
    for (int32 i = 0; i < InventoryItems.Num(); ++i)
    {
        if (InventoryItems[i].ID == ID)
        {
            InventoryItems.RemoveAt(i);
            return;
        }
    }
}

const TArray<FPlayerInventoryItemStruct>& UPlayerInventoryComponent::GetInventoryItems() const
{
    return InventoryItems;
}
