#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ChessHUD.generated.h"



UCLASS()
class CHESS_API AChessHUD : public AHUD {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ChessUserWidget)
		class UChessPointsWidget* widgetPoint1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ChessUserWidget)
		class UChessPointsWidget* widgetPoint2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UserWidget)
		class UChangeMaterialTab* MaterialSwitchingTab;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UserWidget)
		class UWinningScreenWidget* winningScreen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ReplayChessUserWidget)
		class UReplayChessUserWidget* replayUserWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projection2D)
		class UProjection2D* projection2DWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UserWidget)
		class UChessModeWidget* chessModeWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UserWidget)
		class ULevelWidget* levelWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UserWidget)
		class UMenu* menuWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UserWidget)
		class UChessSettingWidget* settingWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UserWidget)
		class USettingButWidget* settingButWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UserWidget)
		class UGameStateWidget* gameStateWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UserWidget)
		class UPlayer1WinWidget* player1WinWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UserWidget)
		class USoundWidget* soundWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UserWidget)
	class USaveGameWidget* saveGameWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UserWidget)
	class ULoadGameWidget* loadGameWidget;
	
	UPROPERTY()
	bool bIsSettingVisible = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UserWidget)
	class UChessPromotionWidget* promotionWidget;

public:
	AChessHUD();

	virtual void BeginPlay() override;

	void showWinningScreen();

	void showReplayScreen();

	void ShowModeSelection();
	void ShowLevelSelection();

	void ShowMenuSelection();

	void ShowSettingSelection(bool Force_on = false);

	void ShowGameStateSelection();

	void ShowPromotionSelection(bool isWhite);
	void HandlePromotion(char pieceType);


	void ShowPlayerWinWidget(const FString& WinnerName);

	void ShowSoundSelection();

	// Trong phần public:
	void ShowSaveGameSelection();

	void ShowLoadGameWidget();
};
