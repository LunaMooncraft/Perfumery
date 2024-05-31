// © 2024 Alicia Schramek

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlayerInventoryComponent.h"
#include "MainGameInstance.generated.h"

UCLASS()
class PERFUMERY_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMainGameInstance();

	UFUNCTION(BlueprintCallable, Category = "Player")
	float GetPlayerMoney() const;

	UFUNCTION(BlueprintCallable, Category = "Player")
	UPlayerInventoryComponent* GetInventoryComponent() const;

	UFUNCTION(BlueprintCallable, Category = "Player")
    FString GetPlayerName() const { return PlayerName; }

    UFUNCTION(BlueprintCallable, Category = "Player")
    UTexture2D* GetPlayerAvatar() const { return PlayerAvatar; }
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
    FString PlayerName;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
    UTexture2D* PlayerAvatar;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
    float PlayerMoney;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Inventory")
	UPlayerInventoryComponent* InventoryComponent;
};
