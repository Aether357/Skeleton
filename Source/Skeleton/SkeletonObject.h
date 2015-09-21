// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SkeletonObject.generated.h"

/*
This is the base class that EVERY Game Object should derive from.
Helper classes / classes that monitor state need to extend this class.
Classes that display things / provide calculations need not extend this class.

Only classes that hold data / states relevant to gameplay need to extend this class, E.X: Characters, Items, Enemies, Attacks/Projectiles.

*/
UCLASS()
class SKELETON_API ASkeletonObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkeletonObject();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
