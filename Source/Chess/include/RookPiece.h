#pragma once

#include "CoreMinimal.h"
#include "ChessPiece_Base.h"
#include "RookPiece.generated.h"

//derived from ChessPiece_Base
UCLASS()
class CHESS_API ARookPiece : public AChessPiece_Base {
	GENERATED_BODY()
public:
	ARookPiece();

	//Overrides the function declared in the base class
	void DetectSelectableGrids(TArray<Atile*>* SelectableGrids) override final;

	// Returns the point of rook piece
	int32 getPiecePoint() override final;
};