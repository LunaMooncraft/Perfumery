// © 2024 Alicia Schramek

#pragma once

#include "CoreMinimal.h"
#include "../BaseStructs/ItemStruct.h"
#include "IngredientStruct.generated.h"

UENUM(BlueprintType)
enum class EIngredientRarity : uint8
{
    Common UMETA(DisplayName = "Common"),
    Uncommon UMETA(DisplayName = "Uncommon"),
    Rare UMETA(DisplayName = "Rare"),
    Epic UMETA(DisplayName = "Epic"),
    Legendary UMETA(DisplayName = "Legendary")
};

USTRUCT(BlueprintType)
struct FIngredientStruct : public FItemStruct
{
    GENERATED_BODY()

public:
    FIngredientStruct() : 
        Origin(TEXT("Unknown")),
        Quantity(0.0f),
        Rarity(EIngredientRarity::Common)
    {}

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ingredient")
    FString Origin; // Geographical origin of the ingredient

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ingredient")
    float Quantity; // Quantity in grams or milliliters

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ingredient")
    EIngredientRarity Rarity;
};