#pragma once
#include "Components/SceneComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "tile.generated.h"

UCLASS()
class CHESS_API Atile : public AActor {
	GENERATED_BODY()
private:
	// Colour of the tile
	UPROPERTY(EditAnywhere)
		bool isBlack;

	//keeps the static mesh of the tile (cube)
	UPROPERTY(VisibleAnyWhere)
		class UStaticMeshComponent* StaticMesh;

	//keeps the materials of the tiles
	UMaterial* LightMaterial;
	UMaterial* DarkMaterial;
	UMaterial* HighlightMaterial;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	//constructor
	Atile();

	// Called every frame, unreal default function
	virtual void Tick(float DeltaTime) override;

	//switches the material of the tiles
	void switchMaterial(UMaterial* LightM, UMaterial* DarkM);

	void switchMaterial(UMaterialInstance* LightM, UMaterialInstance* DarkM);

	//bounds the chesspiece to the tile
	void occupy(class AChessPiece_Base* newPiece);

	//unbounds the chesspiece from the tile
	void unoccupy();

	//highlights this object
	void highlight();

	//unhighlights this object
	void unhighlight();

	//checks whether the tile is occupied or not
	bool isOccupied();

	//keeps the chesspiece bounded to the tile (set in occupy)
	UPROPERTY(EditAnywhere)
		class AChessPiece_Base* currentOccupyingPiece;
};