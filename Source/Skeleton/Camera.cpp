// Fill out your copyright notice in the Description page of Project Settings.

#include "Skeleton.h"
#include "Camera.h"
#include "SkeletonCharacter.h"


// Sets default values
ACamera::ACamera( const FObjectInitializer& ObjectInitializer )
	: Super(ObjectInitializer)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>( this, TEXT( "CameraComponent" ) );

	RootComponent = CameraComponent;
	CameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	CameraComponent->OrthoWidth = 120.0f;
	CameraComponent->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
}

// Called when the game starts or when spawned
void ACamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACamera::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if ( FollowCharacter )
	{
		FVector Loc = FollowCharacter->GetActorLocation();
		Loc.Y = Loc.Y = 50;
		CameraComponent->SetRelativeLocation( Loc );
	}

}

// Called to bind functionality to input
void ACamera::SetupPlayerInputComponent( UInputComponent* InputComponent )
{
	Super::SetupPlayerInputComponent(InputComponent);
}

void ACamera::MoveHorizontal( float Scale )
{
	FVector move = FVector( Scale, 0.0f, 0.0f );
	FVector location = GetActorLocation();
	location += move;
	SetActorRelativeLocation( location );
}

void ACamera::MoveVertical( float Scale )
{
	FVector move = FVector( 0.0f, 0.0f, Scale );
	FVector location = GetActorLocation( );
	location += move;
	SetActorRelativeLocation( location );
}

void ACamera::MoveLeft()
{

}

void ACamera::MoveUp()
{

}

void ACamera::MoveRight()
{

}

void ACamera::MoveDown()
{

}

void ACamera::FollowSkeleton( class ASkeletonCharacter* Character )
{
	FollowCharacter = Character;
}