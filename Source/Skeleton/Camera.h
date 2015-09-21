// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Camera.generated.h"

class ASkeletonMap;

/*
	The Camera is the main control for what the client is seeing.

	This should contain utility functions like the following:

	FollowCharacter(SkeletonChar)
	MoveTo(x,y,z)
	Shake()
	Flash()
	SnapToCharacter()
	MoveLeft()
	MoveRight()
	MoveUp()
	MoveDown()

	etc..., should be easy to use.  This will be the main pawn of the game.
*/
UCLASS()
class SKELETON_API ACamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACamera( const FObjectInitializer& ObjectInitializer );

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

public:
	
	void MoveLeft();

	void MoveUp();

	void MoveRight();

	void MoveDown();

	// Set Focus to the given map at the given tile (Make sure it is loaded up before this is called)
	void SetFocus( ASkeletonMap* Map, uint8 X, uint8 Y );

	void FollowSkeleton( class ASkeletonCharacter* Character );

// Keybind Delegates
public:

	void MoveHorizontal( float Scale );
	void MoveVertical( float Scale );

private:

	class UCameraComponent* CameraComponent;

	class ASkeletonCharacter* FollowCharacter;
};
