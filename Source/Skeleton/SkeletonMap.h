// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SkeletonMap.generated.h"

/*
	A Skeleton Map holds the data for a single map in the game ( IT should have isntance data for each tile, objects/players should be replicated over ).
	This should be loaded onto clients from the server, or it should be generated by the server on the server.

	The Server will manage all of the SkeletonTiles and will replicate the ones that should be replicated over.

	The Client will handle what Maps should be cached/delete/etc...
*/

class ASkeletonTile;
class UPaperTileMap;

UCLASS()
class SKELETON_API ASkeletonMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkeletonMap( const FObjectInitializer& ObjectInitializer );

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	ASkeletonTile* GetTile( uint8 X, uint8 Y );

	// Sets the TileMap Being Used.  This is going to be a base map with all the collision/etc... handled via tiles
	void SetTileMap( UPaperTileMap* Map );

	UPaperTileMap* GetMap();

protected:

	UPROPERTY( BlueprintReadOnly, Category = "TileMap" )
	UPaperTileMap* Map;

	UPROPERTY( EditAnywhere, Category = TileMap )
	class UPaperTileMapComponent* Component;
	
};
