// Fill out your copyright notice in the Description page of Project Settings.

#include "Skeleton.h"
#include "SkeletonTile.h"
#include "PaperSpriteComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ASkeletonTile::ASkeletonTile( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer )
{
	bReplicates = true;
	bAlwaysRelevant = true;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TileVisual = ObjectInitializer.CreateDefaultSubobject<UPaperSpriteComponent>( this, "TileComp" );

	RootComponent = TileVisual;

	TDelta = 0.0f;
	bSelected = false;
}

// Called when the game starts or when spawned
void ASkeletonTile::BeginPlay()
{
	Super::BeginPlay( );
}

// Called every frame
void ASkeletonTile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	TDelta += DeltaTime;
	if ( TDelta > 1.5f )
	{
		TDelta = 0.0f;

	}

}

// Set the Position of the Tile
// x -> x position
// y -> z position
// z -> contains the level
void ASkeletonTile::SetPosition( FVector Position )
{
	FVector relativePosition = FVector( Position.X * 64.0f, -1.0f, Position.Y * -64.0f );
	X = Position.X;
	Y = Position.Y;
	Level = Position.Z;

	TileVisual->SetRelativeLocation( relativePosition );
	TileVisual->SetRelativeRotation( FQuat( FRotator( 0.0f, 0.0f, 0.0f ) ) );
}

// Set the Scale of the Tiles
void ASkeletonTile::SetScale( FVector Scale )
{
	TileVisual->SetRelativeScale3D( Scale );
}

// Mouse begin over the tile
void ASkeletonTile::NotifyActorBeginCursorOver()
{
	MouseBeginCursorOverDelegate.ExecuteIfBound( this );
}

// Mouse end over the tile
void ASkeletonTile::NotifyActorEndCursorOver()
{
	MouseEndCursorOverDelegate.ExecuteIfBound( this );
}

// Mouse clicked on Tile
void ASkeletonTile::NotifyActorOnClicked()
{
	MouseOnClickedDelegate.ExecuteIfBound( this );
	//TileVisual->SetSpriteColor( FLinearColor( 0.f, 200.f, 200.0f, 0.75f ) );
}

// Mouse Released on Tile
void ASkeletonTile::NotifyActorOnReleased()
{
	MouserOnReleasedDelegate.ExecuteIfBound( this );
}

void ASkeletonTile::SetTileLocation( int32 x, int32 y, int32 z, int32 level )
{
	X = x;
	Y = y;
	Z = z;
	Level = level;
}

void ASkeletonTile::SetTileColor( FLinearColor Color )
{
	TileVisual->SetSpriteColor( Color );
}

// Set the Tile to Selected.  This will update the color of the tile to selected/unselected colors
void ASkeletonTile::SetTileSelected( bool bSelected )
{
	this->bSelected = bSelected;
}

// Is this tile currently selected?
bool ASkeletonTile::IsTileSelected()
{
	return bSelected;
}

void ASkeletonTile::SetCollisionData( uint8 CollisionData )
{
	this->CollisionMask = CollisionData;
}

uint8 ASkeletonTile::GetCollisionData()
{
	return CollisionMask;
}

void ASkeletonTile::GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps ) const
{
	Super::GetLifetimeReplicatedProps( OutLifetimeProps );

	DOREPLIFETIME( ASkeletonTile, TDelta );
	DOREPLIFETIME( ASkeletonTile, X );
	DOREPLIFETIME( ASkeletonTile, Y );
	DOREPLIFETIME( ASkeletonTile, Z );
	DOREPLIFETIME( ASkeletonTile, Level );
	DOREPLIFETIME( ASkeletonTile, CollisionMask );
}