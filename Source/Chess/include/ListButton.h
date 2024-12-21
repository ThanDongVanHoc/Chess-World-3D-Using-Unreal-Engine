#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "ListButton.generated.h"

UCLASS()
class CHESS_API UListButton : public UButton {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UScrollBox* toReplayScrollBox;

	class UReplayChessUserWidget* OwningWidget;

public:
    UListButton();

    UFUNCTION()
        void OnClick();

	void ResetPiecesPosition();
};