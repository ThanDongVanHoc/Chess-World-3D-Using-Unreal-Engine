#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WinningScreenWidget.generated.h"

UCLASS()
class CHESS_API UWinningScreenWidget : public UUserWidget {
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
		class UButton* ToReplayButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* NewGameButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* ExitButton;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UReplayChessUserWidget* ReplayScreen;

	UFUNCTION()
		void OnClick_ToReplayScreen();

	UFUNCTION()
		void ResetGame();

	UFUNCTION()
		void ExitGame();

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* Ratio;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* WinnerTextBlock;

	void SetWinner(FString winner);

};
