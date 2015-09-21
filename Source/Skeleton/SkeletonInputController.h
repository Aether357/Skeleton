// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "SkeletonInputController.generated.h"

class ASkeletonCharacter;

/**
 * 
 */
UCLASS()
class SKELETON_API ASkeletonInputController : public APlayerController
{
	GENERATED_BODY()
	
	
public:

	ASkeletonInputController( const FObjectInitializer& ObjectInitializer );

	// Called when the game starts or when spawned
	virtual void BeginPlay( ) override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

protected:

	virtual void SetupInputComponent() override;
// Delegates Here
public:
	// Skeleton Move Horizontal/Vertical Delegate Functions

// Register Functions for Actors that should Register with the Input Controller
	void RegisterSkeleton( ASkeletonCharacter* Skeleton );

private:
	ASkeletonCharacter* OwnedSkeleton;
};
