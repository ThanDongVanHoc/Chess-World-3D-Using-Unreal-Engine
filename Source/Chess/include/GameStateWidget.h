// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameStateWidget.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API UGameStateWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	class UButton* Button_Undo;

	UPROPERTY(meta = (BindWidget))
	class UButton* Button_Redo;

	UPROPERTY(meta = (BindWidget))
	class UButton* Button_SaveState;

	UPROPERTY(meta = (BindWidget))
	class UButton* Button_PlaySave;

	UPROPERTY(meta = (BindWidget))
	class UButton* Button_Restart;

	UFUNCTION()
	void OnUndo();

	UFUNCTION()
	void OnRedo();

	UFUNCTION()
	void OnSave();

	UFUNCTION()
	void OnPlaySave();

	UFUNCTION()
	void OnRestart();

	void UpdateButtonStates();

private:
	class AChessController* Controller;
};
