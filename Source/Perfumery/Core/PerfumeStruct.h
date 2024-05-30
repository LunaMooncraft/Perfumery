// © 2024 Alicia Schramek

#pragma once

#include "CoreMinimal.h"
#include "ItemStruct.h"
#include "PerfumeStruct.generated.h"

USTRUCT(BlueprintType)
struct FPerfumeStruct : public FItemStruct
{
    GENERATED_BODY()

public:
    FPerfumeStruct() : 
        Volume(0.0f),
        Ingredients()
    {}

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perfume")
    float Volume; // in milliliters

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perfume")
    TArray<int32> Ingredients;
};