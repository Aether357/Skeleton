// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Tile.generated.h"

/* Representation*/
UCLASS()
class SKELETON_API ATile : public AActor
{
	GENERATED_BODY( )

public:
	// Sets default values for this actor's properties
	ATile( const FObjectInitializer& ObjectInitializer );

	// Called when the game starts or when spawned
	virtual void BeginPlay( ) override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Set the Position of the Tile
	void SetPosition( FVector Position );

	// Set the Scale of the Tiles
	void SetScale( FVector Scale );

	virtual void GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps ) const override;

	// Set the tile location -- This must be called after creating a new Tile!
	// x -> x location in the world
	// y -> y location in the world
	// z -> the z value so as to set render priority for the block
	// level -> the level of the block.  0 -> ground level
	void SetTileLocation( int32 x, int32 y, int32 z );

	// Set the Color of the Tile
	void SetTileColor( FLinearColor Color );


protected:

	// Visual Representation of the sprite
	class UPaperSpriteComponent* TileVisual;

public:
	UPROPERTY( Replicated )
		float TDelta;

	// X location of the tile
	UPROPERTY( Replicated )
		int32 X;

	// Y location of the tile
	UPROPERTY( Replicated )
		int32 Y;

	// Z location of the tile
	UPROPERTY( Replicated )
		int32 Z;


};
