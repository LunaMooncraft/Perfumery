// © 2024 Alicia Schramek

#include "TycoonGameMode.h"
#include "TopDownCameraPawn.h"
#include "TycoonPlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/DataTable.h"
#include "../Ingredient/IngredientStruct.h"
#include "../Perfume/PerfumeStruct.h"

ATycoonGameMode::ATycoonGameMode()
{
    // Set the custom default pawn
    DefaultPawnClass = ATopDownCameraPawn::StaticClass();

    // Set the custom player controller
    PlayerControllerClass = ATycoonPlayerController::StaticClass();

    // Find and assign the data table for ingredients
    static ConstructorHelpers::FObjectFinder<UDataTable> IngredientDataTableObj(TEXT("DataTable'/Game/DataTables/IngredientDataTable.IngredientDataTable'"));
    if (IngredientDataTableObj.Succeeded())
    {
        IngredientDataTable = IngredientDataTableObj.Object;
    }

    // Find and assign the data table for perfumes
    static ConstructorHelpers::FObjectFinder<UDataTable> PerfumeDataTableObj(TEXT("DataTable'/Game/DataTables/PerfumeDataTable.PerfumeDataTable'"));
    if (PerfumeDataTableObj.Succeeded())
    {
        PerfumeDataTable = PerfumeDataTableObj.Object;
    }
}

void ATycoonGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (IngredientDataTable)
    {
        TArray<FIngredientStruct*> Ingredients;
        IngredientDataTable->GetAllRows(TEXT(""), Ingredients);

        /* 
        for (const FIngredientStruct* Ingredient : Ingredients)
        {
            // UE_LOG(LogTemp, Warning, TEXT("ID: %d, Name: %s, Description: %s, Price: %f, Quantity: %f, Rarity: %d, Origin: %s"), Ingredient->ID, *Ingredient->Name, *Ingredient->Description, Ingredient->Price, Ingredient->Quantity, static_cast<uint8>(Ingredient->Rarity), *Ingredient->Origin);
        }
        */
    }

    if (PerfumeDataTable)
    {
        TArray<FPerfumeStruct*> Perfumes;
        PerfumeDataTable->GetAllRows(TEXT(""), Perfumes);

        /* 
        for (const FPerfumeStruct* Perfume : Perfumes)
        {
            UE_LOG(LogTemp, Warning, TEXT("ID: %d, Name: %s, Description: %s, Price: %f, Volume: %f, Ingredients: %s"), Perfume->ID, *Perfume->Name, *Perfume->Description, Perfume->Price, Perfume->Volume, *FString::JoinBy(Perfume->Ingredients, TEXT(", "), [](int32 IngredientID) { return FString::FromInt(IngredientID); }));
        }
        */
    }
}