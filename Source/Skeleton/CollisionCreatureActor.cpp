// Fill out your copyright notice in the Description page of Project Settings.

#include "Skeleton.h"
#include "CollisionCreatureActor.h"




ACollisionCreatureActor::ACollisionCreatureActor( const FObjectInitializer& ObjectInitializer )
	: Super( ObjectInitializer )
{
	CollisionComponent = ObjectInitializer.CreateDefaultSubobject<UCapsuleComponent>( this, "CollisionComponent" );
	RootComponent = CollisionComponent;
	PrimaryActorTick.bCanEverTick = true;
}

// Accessor for the collision component, should never need this in blueprints
UCapsuleComponent* ACollisionCreatureActor::GetCollisionComponent()
{
	return CollisionComponent;
}
void ACollisionCreatureActor::Tick( float DeltaSeconds )
{
	Super::Tick( DeltaSeconds );

	// Update the creature_mesh with the location of the collision component
	creature_mesh->SetRelativeLocation( CollisionComponent->RelativeLocation );
}
