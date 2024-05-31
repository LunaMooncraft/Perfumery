// © 2024 Alicia Schramek

#pragma once

#include "CoreMinimal.h"
#include "PlayerInventoryItemStruct.generated.h"

USTRUCT(BlueprintType)
struct FPlayerInventoryItemStruct
{
    GENERATED_BODY()

public:
    FPlayerInventoryItemStruct() : 
        ID(0),
        Name(TEXT("Default Item")),
        Quantity(1)
    {}

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Imventory Item")
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Imventory Item")
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Imventory Item")
    float Quantity;
};