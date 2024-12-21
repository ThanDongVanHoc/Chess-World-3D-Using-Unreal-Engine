#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChessPromotionWidget.generated.h"

UCLASS()
class CHESS_API UChessPromotionWidget : public UUserWidget {
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    // Bind các button từ Blueprint
    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Queen;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Rook;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Bishop;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Knight;

    // Các hàm xử lý sự kiện click button
    UFUNCTION()
    void OnClick_Queen();

    UFUNCTION()
    void OnClick_Rook();

    UFUNCTION()
    void OnClick_Bishop();

    UFUNCTION()
    void OnClick_Knight();

    // Hàm set màu cho quân cờ
    void ShowPromotionOptions(bool isWhite);
}; 