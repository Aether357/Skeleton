// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SkeletonCharacter.generated.h"

/*
Representation of a Skeleton in the World.  All animation handling will take place here.  Basically what animation should play.
*/


UCLASS()
class SKELETON_API ASkeletonCharacter : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASkeletonCharacter( const FObjectInitializer& ObjectInitializer );

	// Called when the game starts or when spawned
	virtual void BeginPlay( ) override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

public:

	void MoveHorizontal( float Scale );
	void MoveVertical( float Scale );

public:
	
	// Movement component to set velocity
	UPROPERTY( EditAnywhere, Category = Movement )
	class USimpleMovementComponent* MovementComponent;

	// ref to current actor
	UPROPERTY()
	class ACreatureActor* CurrentActor;

	// A collection which contains all of the possible skeleton animations.  Should be a blueprint with all of this data.
	// I think that I can just use this to represent the Character as the Character will ALWAYS be playing an animation
	// So I should be able to call GetACtiveActor to get the correct actor at all times
	UPROPERTY()
	class ACreatureCollectionActor* SkeletonClips;

	// Array of SkeletonActors with all of their respective animations
	// Need to either make an enumeration of animations or
	UPROPERTY()
	TArray<class ACreatureActor*> SkeletonCreatures;

	// The current Mesh that the skeleton is using to represent itself
	// Need this because there are multiple different creature_mesh's that can be used
	UPROPERTY( VisibleAnywhere, Category = Materials )
	class UCustomProceduralMeshComponent* creature_mesh;

};
