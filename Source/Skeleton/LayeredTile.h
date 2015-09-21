// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LayeredTile.generated.h"

class ATile;

/* A Layered Tile is a collection of tiles separated into different layers

	E.X: Layered Tile Contains:

		COLOR_LAYER -> Layer 0 -> This is a transparency Tile so that I can set any colors to the tile.
		Skeleton 1  -> Layer 1
		Skeleton 2  -> Layer 2
		Tree	    -> Layer 3

		The Tile will contain display information while this collection will handle transparency and things like that

*/
UCLASS()
class SKELETON_API ALayeredTile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALayeredTile( const FObjectInitializer& ObjectInitializer );

	// Called when the game starts or when spawned
	virtual void BeginPlay( ) override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps ) const override;

// layered tile functions
public:

	void AddTileToLayer( ATile* Tile, uint8 Layer );

	void RemoveTileFromLayer( ATile* Tile, uint8 Layer );

	void MoveTileToLayer( ATile* Tile, uint8 NewLayer );

	// tries to find a tile, returns NULL if no tile found
	ATile* FindTile( ATile* Tile );

private:

	UPROPERTY()
	TMap<uint8, ATile*> TileLayers;



};
