#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SaveGameWidget.generated.h"

/**
 * Widget cho phép lưu game vào 3 slot khác nhau
 */
UCLASS()
class CHESS_API USaveGameWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Save1;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Save2;

    UPROPERTY(meta = (BindWidget)) 
    class UButton* Button_Save3;

    UFUNCTION()
    void OnSave1Clicked();

    UFUNCTION()
    void OnSave2Clicked();

    UFUNCTION()
    void OnSave3Clicked();

private:
    void SaveToFile(int slotNumber);
    class AChessController* ChessController;
    
};