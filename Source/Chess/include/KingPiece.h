#pragma once

#include "CoreMinimal.h"
#include "ChessPiece_Base.h"
#include "KingPiece.generated.h"

//derived from ChessPiece_Base
UCLASS()
class CHESS_API AKingPiece : public AChessPiece_Base {
	GENERATED_BODY()
public:
	AKingPiece();

	//Overrides the function declared in the base class
	void DetectSelectableGrids(TArray<Atile*>* SelectableGrids) override final;

	// Returns the point of king piece
	int32 getPiecePoint() override final;
};
