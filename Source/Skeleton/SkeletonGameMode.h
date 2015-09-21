// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "SkeletonGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SKELETON_API ASkeletonGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	ASkeletonGameMode( const FObjectInitializer& ObjectInitializer );

	virtual void StartPlay( ) override;

	virtual void PostLogin( APlayerController* NewPlayer ) override;
	
protected:
	UPROPERTY( BlueprintReadOnly, Category = "TileMap" )
	class UPaperTileMap* TileMap;
	// current map -> only 1 atm

	UPROPERTY( BlueprintReadOnly, Category = "Map" )
	class ASkeletonMap* Map;
};
