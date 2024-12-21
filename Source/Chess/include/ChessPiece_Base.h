#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "tile.h"
#include "ChessPiece_Base.generated.h"
//derived from Actor
UCLASS()
class CHESS_API AChessPiece_Base : public AActor{
	GENERATED_BODY()
private:
	// Colour of the chesspiece
	UPROPERTY(EditAnywhere)
		bool bIsWhite = false;

	// Material to set when piece is selected.
	UPROPERTY(VisibleAnyWhere)
		class UMaterial* SelectedMaterial;

	// Material to set when piece could be eliminated.
	UPROPERTY(VisibleAnyWhere)
		class UMaterial* EliminateMaterial;
public:
	// Sets default values for this actor's properties
	AChessPiece_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Keeps track of whether the piece have been moved or not
	bool neverMove = true;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Call when actor is selected by mouse click.
	void SetSelected();

	// Called when actor is deselected.
	void SetDeselected();

	// Sets eliminate material to piece.
	void SetEliminateMaterial();

	// Changes actors location. Gets one parameter which holds location to move.
	void ChangeLocation(class Atile* newLocation);

	// Sets the board which hosts the chess pieces
	UPROPERTY(EditAnywhere)
		class AChessBoard* HostBoard;

	// Eliminates piece from the game.
	virtual void Eliminate();

	// Detect selectable grids to move the actor. This function does nothing in the parent class. 
	//Therefore it is overridden for every chess piece which performs different sets of actions. 
	virtual void DetectSelectableGrids(TArray<class Atile*>* SelectableGrids);

	// Static mesh for the class. Null by default overridden for every chess piece.
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* StaticMesh;

	// White material for the piece.
	UPROPERTY(VisibleAnyWhere)
		class UMaterial* WhiteMaterial;

	// Black material for the piece.
	UPROPERTY(VisibleAnyWhere)
		class UMaterial* BlackMaterial;

	// The tile occupied by the piece
	UPROPERTY(EditAnywhere)
		class Atile* tileOccupied;

	// Check whether the piece is white or not
	bool isWhite();

	// Set to overlap objects or not
	void setOverlap(bool overlap);

	// Hides the object from user
	void Discard();

	// Places components back to its original state
	void Reset();

	// Restores back the tiles associated with the piece
	void ResetTiling();

	// Changes the material of the piece
	void SwitchMaterial(UMaterial* LightM, UMaterial* DarkM);
	void SwitchMaterial(UMaterialInstance* LightM, UMaterialInstance* DarkM);

	// Returns the point of the piece
	virtual int32 getPiecePoint();

	// Original position of the piece
	FVector OriginalPosition;

	//	Original tile occupied
	Atile* OriginalTile;

	// Thêm các static mesh cho các quân cờ khác nhau
	UPROPERTY(EditAnywhere)
	UStaticMesh* QueenMesh_Asset;
	UPROPERTY(EditAnywhere)
	UStaticMesh* RookMesh_Asset;
	UPROPERTY(EditAnywhere)
	UStaticMesh* BishopMesh_Asset;
	UPROPERTY(EditAnywhere)
	UStaticMesh* KnightMesh_Asset;
	UPROPERTY(EditAnywhere)
	UStaticMesh* KingMesh_Asset;
	
	UPROPERTY(EditAnywhere)
	UStaticMesh* OriginalMesh;
	
	// Hàm để promote pawn
	virtual void PromoteTo(char pieceType);
	
	// Biến lưu loại quân cờ
	//UPROPERTY(EditAnywhere)
	char PieceType = 'P';
	char OriginalType;

protected:

	
};