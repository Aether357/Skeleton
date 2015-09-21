// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SkeletonGenerator.generated.h"

/*
	This is the Skeleton Generator which is a server-side class which will handle all generation of actors.

	Things to keep in mind:

	Server -> Actually creates/manipulates data for everything in the game
	Client -> Displays a visual representation of the data being manipulated
*/

class Map;

UCLASS()
class SKELETON_API ASkeletonGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkeletonGenerator();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	
	
};
