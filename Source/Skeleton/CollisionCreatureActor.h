// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CreatureActor.h"
#include "CollisionCreatureActor.generated.h"

/**
 * Collision Creature Actor to provide a nice and easy way to access the collision data of 
 * a Creature

 * This will be blueprintable
 */
UCLASS(Blueprintable)
class SKELETON_API ACollisionCreatureActor : public ACreatureActor
{
	GENERATED_BODY()
	
public:

	ACollisionCreatureActor( const FObjectInitializer& ObjectInitializer );

	// Accessor for the collision component, should never need this in blueprints
	UCapsuleComponent* GetCollisionComponent();
	
public:

	UPROPERTY( VisibleAnywhere, Category = Collision )
	UCapsuleComponent* CollisionComponent;
	
};
