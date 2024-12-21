#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SoundWidget.generated.h"

UCLASS()
class CHESS_API USoundWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    // Bind các button từ Blueprint
    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Music1;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Music2;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Music3;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_back;

    UPROPERTY(meta = (BindWidget))
    class USlider* Slider_Music;


	UPROPERTY()
	UAudioComponent* CurrentMusicComponent = nullptr;

    // Các hàm xử lý sự kiện
    UFUNCTION()
    void OnMusic1Clicked();

    UFUNCTION()
    void OnMusic2Clicked();

    UFUNCTION()
    void OnMusic3Clicked();

    UFUNCTION()
    void OnBackClicked();

    UFUNCTION()
    void OnVolumeChanged(float SliderValue);

private:
    void PlayMusic(const FString& MusicPath);
    void UpdateButtonColors(UButton* SelectedButton);
};