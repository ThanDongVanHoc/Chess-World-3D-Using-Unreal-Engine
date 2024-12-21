// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChessModeWidget.generated.h"
UCLASS()
class CHESS_API UChessModeWidget : public UUserWidget {
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    // Bind các button từ Blueprint
    UPROPERTY(meta = (BindWidget))
    class UButton* Button_PvP;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_PvAI;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Back;

    // Các hàm xử lý sự kiện click button
    UFUNCTION()
    void OnClick_PvP();

    UFUNCTION()
    void OnClick_PvAI();

    UFUNCTION()
    void OnClick_Back();
    
};
