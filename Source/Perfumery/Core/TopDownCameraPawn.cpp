#include "TopDownCameraPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "InputActionValue.h"

ATopDownCameraPawn::ATopDownCameraPawn()
{
	PrimaryActorTick.bCanEverTick = true;

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

    // Movement speed
    MovementSpeed = 1000.0f;

    // Assign input mapping context and actions
    static ConstructorHelpers::FObjectFinder<UInputMappingContext> PlayerMappingContextFinder(TEXT("/Game/Input/IMC_PlayerInput"));
    PlayerMappingContext = PlayerMappingContextFinder.Object;

    static ConstructorHelpers::FObjectFinder<UInputAction> MoveForwardActionFinder(TEXT("/Game/Input/IA_MoveForward"));
    MoveForwardAction = MoveForwardActionFinder.Object;

    static ConstructorHelpers::FObjectFinder<UInputAction> MoveRightActionFinder(TEXT("/Game/Input/IA_MoveRight"));
    MoveRightAction = MoveRightActionFinder.Object;
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
    }
}

void ATopDownCameraPawn::MoveForward(const FInputActionValue& Value)
{     
	float MovementValue = Value.Get<float>();
    if (MovementValue != 0.0f)
    {
        UE_LOG(LogTemp, Warning, TEXT("MoveForward: %f"), MovementValue * MovementSpeed * GetWorld()->GetDeltaSeconds());
        AddMovementInput(GetActorForwardVector(), MovementValue * MovementSpeed * GetWorld()->GetDeltaSeconds());
    }
}

void ATopDownCameraPawn::MoveRight(const FInputActionValue& Value)
{
    float MovementValue = Value.Get<float>();
    if (MovementValue != 0.0f)
    {
        UE_LOG(LogTemp, Warning, TEXT("MoveRight: %f"), MovementValue * MovementSpeed * GetWorld()->GetDeltaSeconds());
        AddMovementInput(GetActorRightVector(), MovementValue * MovementSpeed * GetWorld()->GetDeltaSeconds());
    }
}

