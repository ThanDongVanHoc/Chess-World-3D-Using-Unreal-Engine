#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ReplayChessUserWidget.generated.h"

UCLASS()
class CHESS_API UReplayChessUserWidget : public UUserWidget {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray <class UImage*> ChessTiles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray <class UImage*> ChessPieces;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UScrollBox* MatchScrollBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UScrollBox* MovesScrollBox;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* Ratio;

	void ScanMatchRecords();
};