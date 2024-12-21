#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChangeMaterialTab.generated.h"

UCLASS()
class CHESS_API UChangeMaterialTab : public UUserWidget {
	GENERATED_BODY()
private:
	bool open = false;

	class AChessBoard* ChessBoard;

public:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UWidgetAnimation* OpenTab;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UWidgetAnimation* CloseTab;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* OpenButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* BlackWhiteButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* GlassButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* WoodButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* MetallicButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* To24KButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* AcrylicButton;

	UFUNCTION()
		void OpenCloseAnimation();

	UFUNCTION()
		void SwitchToDefault();

	UFUNCTION()
		void SwitchToGlass();

	UFUNCTION()
		void SwitchToWood();

	UFUNCTION()
		void SwitchToMetal();

	UFUNCTION()
		void SwitchTo24K();

	UFUNCTION()
		void SwitchToAcrylic();

	void SwitchMaterial(UMaterial* LightP, UMaterial* DarkP, UMaterial* LightT, UMaterial* DarkT);
	void SwitchMaterial(UMaterialInstance* LightP, UMaterialInstance* DarkP, UMaterialInstance* LightT, UMaterialInstance* DarkT);
};
