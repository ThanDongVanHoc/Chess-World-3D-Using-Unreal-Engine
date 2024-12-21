// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "ChessPiece_Base.h"
#include "PawnPiece.generated.h"

//derived from ChessPiece_Base
UCLASS()
class CHESS_API APawnPiece : public AChessPiece_Base {
	GENERATED_BODY()
	
public:	
	APawnPiece();

	//Overrides the function declared in the base class
	void DetectSelectableGrids(TArray<Atile*>* SelectableGrids) override final;

	// Returns the point of pawn piece
	int32 getPiecePoint() override final;
};
