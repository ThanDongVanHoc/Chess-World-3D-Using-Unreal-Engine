#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Player1WinWidget.generated.h"

UCLASS()
class CHESS_API UPlayer1WinWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    // Bind widgets từ Blueprint
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* WinnerText;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Restart;

    // Hàm xử lý sự kiện click button
    UFUNCTION()
    void OnRestart();

    void SetNguoiThang(const FString& WinnerName);
};