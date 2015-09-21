// Fill out your copyright notice in the Description page of Project Settings.

#include "Skeleton.h"
#include "CollisionCreatureActor.h"




ACollisionCreatureActor::ACollisionCreatureActor( const FObjectInitializer& ObjectInitializer )
	: Super( ObjectInitializer )
{
	CollisionComponent = ObjectInitializer.CreateDefaultSubobject<UCapsuleComponent>( this, "CollisionComponent" );

	CollisionComponent->AttachParent = RootComponent;

}

// Accessor for the collision component, should never need this in blueprints
UCapsuleComponent* ACollisionCreatureActor::GetCollisionComponent()
{
	return CollisionComponent;
}