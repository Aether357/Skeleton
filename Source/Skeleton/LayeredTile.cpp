// Fill out your copyright notice in the Description page of Project Settings.

#include "Skeleton.h"
#include "LayeredTile.h"
#include "PaperSpriteComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ALayeredTile::ALayeredTile( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer )
{
	bReplicates = true;
	bAlwaysRelevant = true;
}

// Called when the game starts or when spawned
void ALayeredTile::BeginPlay( )
{
	Super::BeginPlay( );
}

// Called every frame
void ALayeredTile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ALayeredTile::AddTileToLayer( ATile* Tile, uint8 Layer )
{

}

void ALayeredTile::RemoveTileFromLayer( ATile* Tile, uint8 Layer )
{

}

void ALayeredTile::MoveTileToLayer( ATile* Tile, uint8 NewLayer )
{

}

// tries to find a tile, returns NULL if no tile found
ATile* ALayeredTile::FindTile( ATile* Tile )
{
	return NULL;
}

void ALayeredTile::GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps ) const
{
	Super::GetLifetimeReplicatedProps( OutLifetimeProps );
}