#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChessController.h"
#include "SettingButWidget.generated.h"


UCLASS()
class CHESS_API USettingButWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Setting;

    UFUNCTION()
    void OnClick_Setting();

};