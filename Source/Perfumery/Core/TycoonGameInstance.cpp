// © 2024 Alicia Schramek

#include "TycoonGameInstance.h"

UTycoonGameInstance::UTycoonGameInstance() : PlayerMoney(250.0f)
{
    
}


float UTycoonGameInstance::GetPlayerMoney() const
{
    return PlayerMoney;
}