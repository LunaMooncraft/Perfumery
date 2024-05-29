#include "TycoonGameMode.h"
#include "TopDownCameraPawn.h"

ATycoonGameMode::ATycoonGameMode()
{
    // Set default pawn class to BasePawn
    DefaultPawnClass = ATopDownCameraPawn::StaticClass();;
}