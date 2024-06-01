// © 2024 Alicia Schramek

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "Blueprint/UserWidget.h"
#include "GameHelper.generated.h"

UCLASS()
class PERFUMERY_API UGameHelper : public UObject
{
    GENERATED_BODY()

public:
    // Function to add input mapping context
    UFUNCTION(BlueprintCallable, Category = "Input")
    static void AddInputMappingContext(APlayerController* PlayerController, UInputMappingContext* MappingContext, int32 Priority = 0);

    // Function to bind input action to a function
    UFUNCTION(BlueprintCallable, Category = "Input")
    static void BindInputAction(APlayerController* PlayerController, UInputAction* InputAction, ETriggerEvent TriggerEvent, FName FunctionName);

    // Function to find and create widget class
    static TSubclassOf<UUserWidget> FindWidgetClass(const TCHAR* Path);

    // Function to find and assign input mapping context
    static UInputMappingContext* FindInputMappingContext(const TCHAR* Path);

    // Function to find and assign input action
    static UInputAction* FindInputAction(const TCHAR* Path);

    // Function to create widget instance
    template <typename WidgetType>
    static WidgetType* CreateWidgetInstance(APlayerController* PlayerController, TSubclassOf<WidgetType> WidgetClass);

    // Function to add widget to the viewport
    UFUNCTION(BlueprintCallable, Category = "UI")
    static UUserWidget* AddWidgetToViewport(APlayerController* PlayerController, TSubclassOf<UUserWidget> WidgetClass, int32 ZOrder = 0);
};

template <typename WidgetType>
WidgetType* UGameHelper::CreateWidgetInstance(APlayerController* PlayerController, TSubclassOf<WidgetType> WidgetClass)
{
    if (PlayerController && WidgetClass)
    {
        UWorld* World = PlayerController->GetWorld();
        if (World)
        {
            return CreateWidget<WidgetType>(World, WidgetClass);
        }
    }
    return nullptr;
}