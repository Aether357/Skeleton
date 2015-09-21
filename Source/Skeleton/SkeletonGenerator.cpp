// Fill out your copyright notice in the Description page of Project Settings.

#include "Skeleton.h"
#include "SkeletonGenerator.h"


// Sets default values
ASkeletonGenerator::ASkeletonGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASkeletonGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkeletonGenerator::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

