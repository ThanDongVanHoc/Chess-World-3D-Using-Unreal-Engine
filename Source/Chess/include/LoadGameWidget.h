// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoadGameWidget.generated.h"

/**
 * Widget cho phép load game từ 3 slot khác nhau
 */
UCLASS()
class CHESS_API ULoadGameWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Load1;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Load2;

    UPROPERTY(meta = (BindWidget)) 
    class UButton* Button_Load3;

    UFUNCTION()
    void OnLoad1Clicked();

    UFUNCTION()
    void OnLoad2Clicked();

    UFUNCTION()
    void OnLoad3Clicked();

private:
    void LoadFromFile(int slotNumber);
    class AChessController* ChessController;
};