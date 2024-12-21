#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ChessPlayer.generated.h"

UCLASS()
class CHESS_API AChessPlayer : public APawn {
	GENERATED_BODY()

public:
	AChessPlayer();

private:
	UPROPERTY()
		int32 PlayerScore = 0;

	UPROPERTY(EditAnywhere)
		FText PlayerName = FText::FromString("Player1");

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		class AChessBoard* Board;

	UPROPERTY(EditAnywhere)
		class AChessController* ChessController;

	UPROPERTY(EditAnywhere)
		bool bIsWhite = false;

	class AChessPiece_Base* CurrentSelectedPiece;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
		class USpringArmComponent* CameraSpringArm;

	UPROPERTY()
		class UCameraComponent* Camera;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool isPending = false;

	void addScore(int32 points);

	FText getName();

	int32 getScore();


	FVector GetCameraPanDirection();

	bool isWhite();

	void setIsWhite(bool newValue);

	void setCurrentPiece(class AChessPiece_Base* newPiece);

	FVector2D mousePosition = FVector2D(NULL, NULL);

	void setScore(int32 newScore);
};