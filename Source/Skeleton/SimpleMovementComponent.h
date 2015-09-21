// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "SimpleMovementComponent.generated.h"


/*
	SimpleMovementComponent is made to provide Simple Movement/Collision for an Actor.

	For example, in a 2D game, you may simply want to set velocitys for x and z, ignore all acceleration (maybe have it?), and handle collisions.
	That is what this Component is for.  This component can be attached to any actor that needs simple movement.
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SKELETON_API USimpleMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USimpleMovementComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	// Initialize the component
	void InitializeComponent() override;

	void RegisterOwner( AActor* Owner );
	void RegisterCollisionObject( USphereComponent* Component );
	void RegisterCollisionActor( AActor* Actor );

	void SetVelocity( FVector NewVelocity );
	void SetXVelocity( float XVelocity );
	void SetZVelocity( float ZVelocity );

	void ZeroVelocity();

public:
	// Delegate Function Calls
	UFUNCTION()
	void NotifyActorBeginOverlap( class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult );

	UFUNCTION()
	void NotifyActorEndOverlap( class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex );

	UFUNCTION()
	void NotifyBeginOverlap( AActor* OtherActor );

	UFUNCTION()
	void NotifyEndOverlap( AActor* OtherActor );

	UFUNCTION()
	void NotifyHit( class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit );

private:
	UPROPERTY()
	FVector Velocity;

	UPROPERTY()
	class AActor* Owner;

	UPROPERTY()
	FVector PreviousLocation;

	UPROPERTY()
	bool bOverlapped;
	
};
