#pragma once
#include "CoreMinimal.h"
#include "ChessPiece_Base.h"
#include "KnightPiece.generated.h"

//derived from ChessPiece_Base
UCLASS()
class CHESS_API AKnightPiece : public AChessPiece_Base {
	GENERATED_BODY()
public:
	AKnightPiece();

	//Overrides the function declared in the base class
	void DetectSelectableGrids(TArray<Atile*>* SelectableGrids) override final;

	// Returns the point of knight piece
	int32 getPiecePoint() override final;
};