// © 2024 Alicia Schramek

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerInventoryItemStruct.h"
#include "PlayerInventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PERFUMERY_API UPlayerInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPlayerInventoryComponent();

protected:
	virtual void BeginPlay() override;

public:	
    UFUNCTION(BlueprintCallable, Category = "Player Inventory")
    void AddItem(const FPlayerInventoryItemStruct& Item);

    UFUNCTION(BlueprintCallable, Category = "Player Inventory")
    void RemoveItem(int32 ItemID);

    UFUNCTION(BlueprintCallable, Category = "Player Inventory")
    const TArray<FPlayerInventoryItemStruct>& GetInventoryItems() const;

private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Inventory", meta = (AllowPrivateAccess = "true"))
    TArray<FPlayerInventoryItemStruct> InventoryItems;
};
