// © 2024 Alicia Schramek

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TycoonGameInstance.generated.h"

UCLASS()
class PERFUMERY_API UTycoonGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
    UTycoonGameInstance();

	UFUNCTION(BlueprintCallable, Category = "Player")
    FString GetPlayerName() const { return PlayerName; }

    UFUNCTION(BlueprintCallable, Category = "Player")
    UTexture2D* GetPlayerAvatar() const { return PlayerAvatar; }
	
private:
	UPROPERTY()
    FString PlayerName;

    UPROPERTY()
    UTexture2D* PlayerAvatar;
};
