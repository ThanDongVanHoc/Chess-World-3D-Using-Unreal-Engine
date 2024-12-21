#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ChessPiece_Base.h"
#include "ChessTypes.h"

#include "MyLibrary.h"

#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Validator.h"





#include "GameFramework/Character.h"
#include "ChessController.generated.h"

//forward declarations
class AChessPlayer;
class AChessBoard;
class Atile;

// Thêm enum này ở đầu file, sau các forward declarations
UENUM()
enum class EGameMode : uint8 {
    PvP     UMETA(DisplayName = "Player vs Player"),
    PvAI    UMETA(DisplayName = "Player vs AI")
};
struct LogicBoardState {
    Board board;
    int turnCount;
    bool isCastling = false;    // Biến để theo dõi nước nhập thành
    bool isEnPassant = false;   // Biến để theo dõi nước tốt qua đường
	bool isPromotion = false;  // Thêm biến này
};

// Enum trạng thái trò chơi
enum GameState {
    ONGOING = 0,
    WHITE_WINS = 1,
    BLACK_WINS = 2,
    DRAW = 3
};

UCLASS()
class CHESS_API AChessController : public APlayerController {
	GENERATED_BODY()

private:
	// Pointer to the chessboard
	UPROPERTY(EditAnywhere)
		AChessBoard* ChessBoard;



	// Pointer array to store all the tiles valid to move into
	TArray<Atile*> SelectableGrids;

	// Pointer array to store all the pieces that might get eliminated
	TArray<AChessPiece_Base*> EliminatePieces;

	// bool to check whether the left click is being held or not
	bool isPending = false;

	// bool to check whether anything is selected or not
	bool IsAnythingSelected = false;

	// Temporarily store a piece's location
	FVector PieceLocation;

	// Stores the game's directory path
	FString TextFileDirectory;

	// Stores the moves made by the players
	TArray<FString> GameLog;

	// Function to bind with the left click input
	void OnLeftMouseClick();
	
	void AiLeftClick(char tp, int x, int y, int fX, int fY);

	// Function to bind when left click is released
	void OnLeftMouseRelease();

	void AiLeftRelease(char tp, int x, int y, int fX, int fY);
	// Function to bind with the right click input
	void OnRightMouseClick();
	void AiSelectPiece(int x, int y);
	// Function to select a chess piece
	void SelectPiece(int x, int y);

	

	// Function to highlight the selectable grids
	void HighlightSelectableGrids(int x, int y);

	// Funtion to deselect the selected chess piece
	void Deselect();

	// Function to switch between the players
	void SwitchPlayer();

	// Function to execute a move
	void MakeMove();

	void AiMakeMove(Board &board, int turn, char tp, int x, int y, int fX, int fY);

	//FakeClick
	void AiFakeClick(Board &board, int turn);

	// Function to set the key bindings
	virtual void SetupInputComponent() override;

	// Pointer to the chess HUD
	class AChessHUD* HUD;

	// Thêm các thuộc tính mới
	
	UPROPERTY(EditAnywhere)
		EGameMode CurrentGameMode;
	
	TArray<FChessMove> MoveHistory;
	TArray<FChessMove> RedoStack;
	FGameStatus SavedState;
	bool bHasSavedState = false;

	FTimerHandle MoveTimerHandle;
	
	//----------------------------------------------------
	
	// Helper functions để chuyển đổi tọa độ
	std::pair<int, int> ConvertToLogicCoordinates(const FVector& position);
	
	// check valid move to make move
	int IsValidMove(Board & board, const FVector& fromPos, const FVector& toPos, int ISP, int turn);


	int ContMove(Board & board, char tp, int x, int y, int fX, int fY, int ISP, int turn);


	UPROPERTY()
	class UChessPromotionWidget* PromotionWidget;

	bool bAwaitingPromotion;
	AChessPiece_Base* PawnToPromote;
	FVector2D PromotionPosition;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UChessPromotionWidget> PromotionWidgetClass;



	

	// Các biến cho bàn cờ logic
    Board SavedLogicBoard;      // Lưu trạng thái bàn cờ logic
    int32 SavedLogicTurnCount;  // Lưu lượt chơi
public:
	// Pointer to the first player
	UPROPERTY(EditAnyWhere)
		AChessPlayer* PlayerOne;

	// Pointer to the second player
	UPROPERTY(EditAnyWhere)
		AChessPlayer* PlayerTwo;
	// Player create
	int cntTurn = 1;
    bool isCastling = false;  // Biến để theo dõi nước nhập thành

	bool isEnPassant = false; // Biến để theo dõi nước tốt qua đường
    bool isPromotion = false;  // Thêm biến này
	// Thêm vào ChessController.h
	Board logicBoard;
	void InitializeLogicBoard(Board & board);
	TArray<LogicBoardState> LogicMoveHistory;
    TArray<LogicBoardState> LogicRedoStack;


	// To set that the game is over
	bool endGame = false;
	char TypePromotion;
	AChessController();

	virtual void BeginPlay() override;

	// Returns the bool isPending
	bool getPending();

	// Returns the address of current player
	AChessPlayer* GetCurrentPlayer();

	AChessPlayer* GetPlayerOne();

	AChessPlayer* GetPlayerTwo();

	// Pointer to the chess piece selected
	AChessPiece_Base* SelectedPiece;

	// Pointer to the tile selected
	Atile* SelectedGrid;

	// Pointer to material when a piece is selected
	UPROPERTY(VisibleAnyWhere)
		class UMaterial* SelectedMaterial;

	// Pointer to players
	AChessPlayer* PreviousPlayer;
	AChessPlayer* CurrentPlayer = PlayerOne;

	void ClearRecords();
	int CurrentGameLevel = 3;
	// Thêm các hàm mới
	void SetGameMode(EGameMode NewMode);

	void SettingLevelClicked();
	void SetGameLevel(int lv);
	void SettingModeClicked();




	void CallingSettingSelection(bool Force_on = false);
	EGameMode GetGameMode() const { return CurrentGameMode; }

	void SaveCurrentMove(AChessPiece_Base* Piece, Atile* From, Atile* To, AChessPiece_Base* Captured);
	void UndoLastMove();
	void RedoLastMove();
	void SaveGameState();
	void LoadGameState();
	void ValidateAndFixMoveHistory();
	void ResetToInitialState();
	void PlayNextSavedMove();

	GameState isGameOverBackup(Board &board, int turn);

	void UpdateGraphicsFromLogicBoard(int fX, int fY);

	void DebugGraphicBoard();
	
	bool CanUndo() const { return LogicMoveHistory.Num() > 0; }
	bool CanRedo() const { return LogicRedoStack.Num() > 0; }
	bool HasSavedState() const { return bHasSavedState; }

	// ... các hàm public khác ...
    int32 GetCurrentTurn() const { return cntTurn; }
    bool GetIsCastling() const { return isCastling; }
    bool GetIsEnPassant() const { return isEnPassant; }
    bool GetIsPromotion() const { return isPromotion; }

	UFUNCTION(BlueprintCallable)
	void SwitchToThirdPersonMode();
    UPROPERTY()
    bool bIsInChessMode;
    // Add these methods
    void SwitchToChessMode();
	void OnSwitchMode();
	void PlaySoundFromPath(const FString& SoundPath);

	void OnPromotionPieceSelected(char pieceType);
	void HandlePromotionSelection(char pieceType);
    // Add these public methods
    Board& GetLogicBoard() { return logicBoard; }
    void ResetGame();
	
    UFUNCTION()
    void ShowSoundWidget();
	
protected:
	UPROPERTY()
	ACharacter* ThirdPersonCharacter;
};

