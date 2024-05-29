#include "TycoonGameMode.h"
#include "BasePawn.h"

ATycoonGameMode::ATycoonGameMode()
{
    // Set default pawn class to BasePawn
    DefaultPawnClass = ABasePawn::StaticClass();;
}