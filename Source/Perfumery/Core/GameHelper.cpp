// © 2024 Alicia Schramek

#include "GameHelper.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "UObject/ConstructorHelpers.h"

void UGameHelper::AddInputMappingContext(APlayerController* PlayerController, UInputMappingContext* MappingContext, int32 Priority)
{
    if (PlayerController && MappingContext)
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(MappingContext, Priority);
        }
    }
}

void UGameHelper::BindInputAction(APlayerController* PlayerController, UInputAction* InputAction, ETriggerEvent TriggerEvent, FName FunctionName)
{
    if (PlayerController && InputAction)
    {
        if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
        {
            EnhancedInput->BindAction(InputAction, TriggerEvent,PlayerController, FunctionName);
        }
    }
}

TSubclassOf<UUserWidget> UGameHelper::FindWidgetClass(const TCHAR* Path)
{
    ConstructorHelpers::FClassFinder<UUserWidget> WidgetFinder(Path);
    if (WidgetFinder.Succeeded())
    {
        return WidgetFinder.Class;
    }
    return nullptr;
}

UInputMappingContext* UGameHelper::FindInputMappingContext(const TCHAR* Path)
{
    ConstructorHelpers::FObjectFinder<UInputMappingContext> MappingContextFinder(Path);
    if (MappingContextFinder.Succeeded())
    {
        return MappingContextFinder.Object;
    }
    return nullptr;
}

UInputAction* UGameHelper::FindInputAction(const TCHAR* Path)
{
    ConstructorHelpers::FObjectFinder<UInputAction> ActionFinder(Path);
    if (ActionFinder.Succeeded())
    {
        return ActionFinder.Object;
    }
    return nullptr;
}

UUserWidget* UGameHelper::AddWidgetToViewport(APlayerController* PlayerController, TSubclassOf<UUserWidget> WidgetClass, int32 ZOrder)
{
    if (PlayerController && WidgetClass)
    {
        
        UWorld* World = PlayerController->GetWorld();
        if (World)
        {
            UUserWidget* WidgetInstance = CreateWidget<UUserWidget>(World, WidgetClass);
            if (WidgetInstance)
            {
                WidgetInstance->AddToViewport(ZOrder);
                return WidgetInstance;
            }
        }
    }
    return nullptr;
}