// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "tile.h"
#include "Containers/StaticArray.h"
#include "ChessBoard.generated.h"

UCLASS()
class CHESS_API AChessBoard : public AActor
{
	GENERATED_BODY()

public:
	AChessBoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	// Pointer array to hold every tile's address
	UPROPERTY(EditAnywhere)
		TArray <Atile*> TilesCollection;

	// Pointer array to the borders to the board
	UPROPERTY(EditAnywhere)
		TArray <AActor*> ChessBorders;

	// Material for white tiles
	UPROPERTY(EditAnywhere)
		class UMaterial* LightMaterial;

	// Material for black tiles
	UPROPERTY(EditAnywhere)
		class UMaterial* DarkMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterial* WhitePieceMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterial* BlackPieceMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterial* WhiteTileMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterial* BlackTileMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* WhitePieceGlassMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* BlackPieceGlassMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* WhiteTileGlassMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* BlackTileGlassMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* WhitePieceWoodenMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* BlackPieceWoodenMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* WhiteTileWoodenMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* BlackTileWoodenMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* WhitePieceMetallicMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* BlackPieceMetallicMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* WhiteTileMetallicMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* BlackTileMetallicMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* WhitePiece24KMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* BlackPiece24KMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* WhiteTile24KMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* BlackTile24KMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterial* WhitePieceAcrylicMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterial* BlackPieceAcrylicMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* WhiteTileAcrylicMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInstance* BlackTileAcrylicMaterial;
	
};
