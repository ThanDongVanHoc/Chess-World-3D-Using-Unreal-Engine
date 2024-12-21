#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChessController.h"
#include "ChessSettingWidget.generated.h"


UCLASS()
class CHESS_API UChessSettingWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Start;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Level;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Mode;

    // Thêm button mới
    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Music_Select;
    // Thêm button mới
    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Exit;

    UFUNCTION()
    void OnClick_Start();

    UFUNCTION()
    void OnClick_Level();

    UFUNCTION()
    void OnClick_Mode();

    // Thêm handler cho button mới
    UFUNCTION()
    void OnClick_MusicSelect();

    // Thêm handler cho button mới
    UFUNCTION()
    void OnClick_Exit();

};