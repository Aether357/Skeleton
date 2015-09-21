// Fill out your copyright notice in the Description page of Project Settings.

#include "Skeleton.h"
#include "SimpleMovementComponent.h"


// Sets default values for this component's properties
USimpleMovementComponent::USimpleMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	PreviousLocation = FVector( 0.0f, 0.0f, 0.0f );
	Velocity = FVector( 0.0f, 0.0f, 0.0f );
	bOverlapped = false;
	// ...
}


// Called when the game starts
void USimpleMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USimpleMovementComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Need to move the Owner based on DeltaTime/Velocity
	// Need to check if I am overlapping something
	if ( GetOwner() )
	{
		FVector NewLoc = GetOwner()->GetActorLocation() + Velocity*DeltaTime*25.0f;
		GetOwner()->SetActorLocation( NewLoc, true );
	}

	
}

void USimpleMovementComponent::RegisterOwner( AActor* Owner )
{
	this->Owner = Owner;
}

void USimpleMovementComponent::InitializeComponent()
{
	// Register collision events from the actor to functions here

}

void  USimpleMovementComponent::NotifyActorBeginOverlap( AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult )
{
	GEngine->AddOnScreenDebugMessage( -1, 5.f, FColor::Red, TEXT( "Overlap" ) );
}

void  USimpleMovementComponent::NotifyActorEndOverlap( AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex )
{
	GEngine->AddOnScreenDebugMessage( -1, 5.f, FColor::Red, TEXT( "End Overlap" ) );
}

void USimpleMovementComponent::NotifyBeginOverlap( AActor* OtherActor )
{
	GEngine->AddOnScreenDebugMessage( -1, 5.f, FColor::Red, TEXT( "Overlap" ) );
}

void USimpleMovementComponent::NotifyEndOverlap( AActor* OtherActor )
{
	GEngine->AddOnScreenDebugMessage( -1, 5.f, FColor::Red, TEXT( "End Overlap" ) );
}

void USimpleMovementComponent::NotifyHit( class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit )
{
}

void USimpleMovementComponent::RegisterCollisionActor( AActor* OtherActor )
{
	/*OtherActor->OnActorBeginOverlap.AddDynamic( this, &USimpleMovementComponent::NotifyBeginOverlap );
	OtherActor->OnActorEndOverlap.AddDynamic( this, &USimpleMovementComponent::NotifyEndOverlap );*/
}

void USimpleMovementComponent::RegisterCollisionObject( USphereComponent* Component )
{
	/*
	Component->OnComponentBeginOverlap.AddDynamic( this, &USimpleMovementComponent::NotifyActorBeginOverlap );
	Component->OnComponentEndOverlap.AddDynamic( this, &USimpleMovementComponent::NotifyActorEndOverlap );
	Component->OnComponentHit.AddDynamic( this, &USimpleMovementComponent::NotifyHit );*/
}

void USimpleMovementComponent::SetVelocity( FVector NewVelocity )
{
	Velocity = NewVelocity;
}

void USimpleMovementComponent::SetXVelocity( float XVelocity )
{
	Velocity.X = XVelocity;
}

void USimpleMovementComponent::SetZVelocity( float ZVelocity )
{
	Velocity.Z = ZVelocity;
}

void USimpleMovementComponent::ZeroVelocity( )
{
	Velocity = FVector( 0.0f, 0.0f, 0.0f );
}