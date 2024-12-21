// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LevelWidget.generated.h"
UCLASS()
class CHESS_API ULevelWidget : public UUserWidget {
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    // Bind các button từ Blueprint
    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Easy;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Medium;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Hard;
    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Back;

    // Các hàm xử lý sự kiện click button
    UFUNCTION()
    void OnClick_Easy();

    UFUNCTION()
    void OnClick_Medium();

    UFUNCTION()
    void OnClick_Hard();


    UFUNCTION()
    void OnClick_Back();
};
