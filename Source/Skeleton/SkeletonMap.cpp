// Fill out your copyright notice in the Description page of Project Settings.

#include "Skeleton.h"
#include "SkeletonMap.h"
#include "PaperTileMap.h"
#include "PaperTileMapComponent.h"

// Sets default values
ASkeletonMap::ASkeletonMap( const FObjectInitializer& ObjectInitializer )
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Component = ObjectInitializer.CreateDefaultSubobject<UPaperTileMapComponent>( this, "RenderComponent" );
	RootComponent = Component;
}

// Called when the game starts or when spawned
void ASkeletonMap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkeletonMap::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void ASkeletonMap::SetTileMap( UPaperTileMap* Map )
{
	this->Map = Map;
	Component->SetTileMap( Map );
	Component->SetCollisionEnabled( ECollisionEnabled::QueryAndPhysics );
	Component->SetEnableGravity( false );
	Component->bGenerateOverlapEvents = true;
	Component->SetNotifyRigidBodyCollision( true );
}

UPaperTileMap* ASkeletonMap::GetMap()
{
	return Map;
}