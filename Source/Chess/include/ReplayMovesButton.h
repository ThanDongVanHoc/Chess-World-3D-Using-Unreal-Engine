#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "ReplayMovesButton.generated.h"

UCLASS()
class CHESS_API UReplayMovesButton : public UButton {
	GENERATED_BODY()

public:

	class UReplayChessUserWidget* OwningWidget;

	UReplayMovesButton();

	FString From;
	
	FString To;

	int index = 0;

	bool take = false;

	UFUNCTION()
		void OnClick();

	void ResetPiecesPosition();
};
