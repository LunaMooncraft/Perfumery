// © 2024 Alicia Schramek

#include "TopDownCameraPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "InputActionValue.h"

ATopDownCameraPawn::ATopDownCameraPawn()
{
	PrimaryActorTick.bCanEverTick = true;

    // Root component
    USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    RootComponent = Root;

    // Spring Arm component
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 800.0f; // The camera distance
    SpringArm->bEnableCameraLag = true;
    SpringArm->CameraLagSpeed = 3.0f;

    // Camera component
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

    // Movement component
    MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));

    // Movement settings
    MovementSpeed = 1000.0f;
    MouseSensitivity = 10.1f;

    // Zoom settings
    ZoomSpeed = 100.0f;
    MinZoom = 300.0f;
    MaxZoom = 1500.0f;


    // Assign input mapping context and actions
    static ConstructorHelpers::FObjectFinder<UInputMappingContext> PlayerMappingContextFinder(TEXT("/Game/Input/IMC_PlayerInput"));
    PlayerMappingContext = PlayerMappingContextFinder.Object;

    static ConstructorHelpers::FObjectFinder<UInputAction> MoveForwardActionFinder(TEXT("/Game/Input/IA_MoveForward"));
    MoveForwardAction = MoveForwardActionFinder.Object;

    static ConstructorHelpers::FObjectFinder<UInputAction> MoveRightActionFinder(TEXT("/Game/Input/IA_MoveRight"));
    MoveRightAction = MoveRightActionFinder.Object;

    static ConstructorHelpers::FObjectFinder<UInputAction> MoveMouseActionFinder(TEXT("/Game/Input/IA_MoveMouse"));
    MoveMouseAction = MoveMouseActionFinder.Object;

    static ConstructorHelpers::FObjectFinder<UInputAction> ZoomActionFinder(TEXT("/Game/Input/IA_ZoomMouseWheel"));
    ZoomAction = ZoomActionFinder.Object;
}

void ATopDownCameraPawn::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(PlayerMappingContext, 0);
        }
    }
}

void ATopDownCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATopDownCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &ATopDownCameraPawn::MoveForward);
        EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &ATopDownCameraPawn::MoveRight);
        EnhancedInputComponent->BindAction(MoveMouseAction, ETriggerEvent::Triggered, this, &ATopDownCameraPawn::MoveMouse);
        EnhancedInputComponent->BindAction(ZoomAction, ETriggerEvent::Triggered, this, &ATopDownCameraPawn::Zoom);
    }
}

void ATopDownCameraPawn::MoveForward(const FInputActionValue& Value)
{     
	float MovementValue = Value.Get<float>();
    if (MovementValue != 0.0f)
    {
        // UE_LOG(LogTemp, Warning, TEXT("MoveForward: %f"), MovementValue * MovementSpeed * GetWorld()->GetDeltaSeconds());
        AddMovementInput(GetActorForwardVector(), MovementValue * MovementSpeed * GetWorld()->GetDeltaSeconds());
    }
}

void ATopDownCameraPawn::MoveRight(const FInputActionValue& Value)
{
    float MovementValue = Value.Get<float>();
    if (MovementValue != 0.0f)
    {
        // UE_LOG(LogTemp, Warning, TEXT("MoveRight: %f"), MovementValue * MovementSpeed * GetWorld()->GetDeltaSeconds());
        AddMovementInput(GetActorRightVector(), MovementValue * MovementSpeed * GetWorld()->GetDeltaSeconds());
    }
}

void ATopDownCameraPawn::MoveMouse(const FInputActionValue& Value)
{
    FVector2D MouseValue = Value.Get<FVector2D>();
    if (!MouseValue.IsZero())
    {
        // Calculate new position
        FVector NewLocation = GetActorLocation();
        NewLocation += FVector(-MouseValue.Y * MouseSensitivity, MouseValue.X * MouseSensitivity, 0.0f);
        
        // Update actor's position
        SetActorLocation(NewLocation);

        // UE_LOG(LogTemp, Warning, TEXT("MoveMouse: X: %f, Y: %f"), MouseValue.X, MouseValue.Y);
    }
}

void ATopDownCameraPawn::Zoom(const FInputActionValue& Value)
{
    float ZoomValue = Value.Get<float>();
    if (ZoomValue != 0.0f)
    {
        float NewArmLength = FMath::Clamp(SpringArm->TargetArmLength - (ZoomValue * ZoomSpeed), MinZoom, MaxZoom);
        SpringArm->TargetArmLength = NewArmLength;

        // UE_LOG(LogTemp, Warning, TEXT("Zoom: %f"), NewArmLength);
    }
}

