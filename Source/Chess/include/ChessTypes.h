#pragma once
#include "CoreMinimal.h"
#include "ChessTypes.generated.h"

USTRUCT()
struct FChessMove
{
    GENERATED_BODY()

    UPROPERTY()
    class AChessPiece_Base* MovedPiece = nullptr;
    
    UPROPERTY()
    class Atile* FromTile = nullptr;
    
    UPROPERTY()
    class Atile* ToTile = nullptr;
    
    UPROPERTY()
    class AChessPiece_Base* CapturedPiece = nullptr;
    
    UPROPERTY()
    int32 PlayerOneScore = 0;
    
    UPROPERTY()
    int32 PlayerTwoScore = 0;
};

USTRUCT()
struct FGameStatus
{
    GENERATED_BODY()

    UPROPERTY()
    TArray<FChessMove> MoveHistory;

    UPROPERTY()
    TArray<FChessMove> RedoStack;

    UPROPERTY()
    int32 PlayerOneScore;

    UPROPERTY()
    int32 PlayerTwoScore;

    UPROPERTY()
    int32 CurrentMoveCount;
};