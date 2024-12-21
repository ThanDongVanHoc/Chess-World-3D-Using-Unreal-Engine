#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Projection2D.generated.h"

UCLASS()
class CHESS_API UProjection2D : public UUserWidget {
	GENERATED_BODY()
public:
	UPROPERTY(Editanywhere, BlueprintReadWrite)
		TArray <class UImage*> Tiles2D;
	
	UPROPERTY(Editanywhere, BlueprintReadWrite)
		TArray <class UImage*> Pieces2D;

	void update2DBoard(const FString from, const FString to, bool take);

	void reset2DBoard();
};
