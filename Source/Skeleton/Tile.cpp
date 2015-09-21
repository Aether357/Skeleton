// Fill out your copyright notice in the Description page of Project Settings.

#include "Skeleton.h"
#include "Tile.h"
#include "PaperSpriteComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ATile::ATile( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer )
{
	bReplicates = true;
	bAlwaysRelevant = true;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TileVisual = ObjectInitializer.CreateDefaultSubobject<UPaperSpriteComponent>( this, "TileComp" );

	RootComponent = TileVisual;

	TDelta = 0.0f;
}

// Called when the game starts or when spawned
void ATile::BeginPlay( )
{
	Super::BeginPlay( );
}

// Called every frame
void ATile::Tick( float DeltaTime )
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
void ATile::SetPosition( FVector Position )
{
	FVector relativePosition = FVector( Position.X * 64.0f, -1.0f, Position.Y * -64.0f );
	X = Position.X;
	Y = Position.Y;

	TileVisual->SetRelativeLocation( relativePosition );
	TileVisual->SetRelativeRotation( FQuat( FRotator( 0.0f, 0.0f, 0.0f ) ) );
}

// Set the Scale of the Tiles
void ATile::SetScale( FVector Scale )
{
	TileVisual->SetRelativeScale3D( Scale );
}

void ATile::SetTileLocation( int32 x, int32 y, int32 z )
{
	X = x;
	Y = y;
	Z = z;
}

void ATile::SetTileColor( FLinearColor Color )
{
	TileVisual->SetSpriteColor( Color );
}


void ATile::GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps ) const
{
	Super::GetLifetimeReplicatedProps( OutLifetimeProps );

	DOREPLIFETIME( ATile, TDelta );
	DOREPLIFETIME( ATile, X );
	DOREPLIFETIME( ATile, Y );
	DOREPLIFETIME( ATile, Z );
}