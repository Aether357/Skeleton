// Fill out your copyright notice in the Description page of Project Settings.

#include "Skeleton.h"
#include "SkeletonInputController.h"
#include "SkeletonCharacter.h"



ASkeletonInputController::ASkeletonInputController( const FObjectInitializer& ObjectInitializer )
	: Super( ObjectInitializer )
{

}

// Called when the game starts or when spawned
void ASkeletonInputController::BeginPlay()
{

}

// Called every frame
void ASkeletonInputController::Tick( float DeltaSeconds )
{

}


void ASkeletonInputController::SetupInputComponent()
{
	Super::SetupInputComponent();
}

/* Setup the Binds Here */
void ASkeletonInputController::RegisterSkeleton( ASkeletonCharacter* Skeleton )
{
	OwnedSkeleton = Skeleton;

	const UInputSettings* settings = GetDefault<UInputSettings>( );

	//Create movement mappings for upwards and downwards movement, the float value tells if we are moving the paddle up or down
	const FInputAxisKeyMapping upKey( "MoveV", EKeys::Up, 1.0f );
	const FInputAxisKeyMapping downKey( "MoveV", EKeys::Down, -1.0f );
	const FInputAxisKeyMapping rightKey( "MoveH", EKeys::Right, 1.0f );
	const FInputAxisKeyMapping leftKey( "MoveH", EKeys::Left, -1.0f );

	// Add the axis mappings
	// Once this code is executed, these mappings will be added in the editors Input Settings!
	( (UInputSettings*)settings )->AddAxisMapping( upKey );
	( (UInputSettings*)settings )->AddAxisMapping( downKey );
	( (UInputSettings*)settings )->AddAxisMapping( rightKey );
	( (UInputSettings*)settings )->AddAxisMapping( leftKey );

	// Bind the axis - if we press up, the function is called with 1.0.  if we press down, the function is called with -1.0.
	// if we do nothing, the function is called with 0.0f
	InputComponent->BindAxis( "MoveV", OwnedSkeleton, &ASkeletonCharacter::MoveVertical );
	InputComponent->BindAxis( "MoveH", OwnedSkeleton, &ASkeletonCharacter::MoveHorizontal );
}