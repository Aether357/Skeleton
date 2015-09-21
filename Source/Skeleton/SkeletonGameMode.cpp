// Fill out your copyright notice in the Description page of Project Settings.

#include "Skeleton.h"
#include "SkeletonGameMode.h"
#include "SkeletonGameState.h"
#include "SkeletonPlayerState.h"
#include "Camera.h"
#include "SkeletonCharacter.h"
#include "SkeletonMap.h"
#include "PaperTileMap.h"
#include "SkeletonInputController.h"

ASkeletonGameMode::ASkeletonGameMode( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer )
{

	//PlayerControllerClass = AMousePlayerController::StaticClass( );

	//HUDClass = ConstructorHelpers::FClassFinder<AHUD>( TEXT( "Blueprint'/Game/DwarfHUD/BP_DwarvenHud.BP_DwarvenHud_c'" ) ).Class;
	DefaultPawnClass = ACamera::StaticClass();

	GameStateClass = ASkeletonGameState::StaticClass();
	PlayerStateClass = ASkeletonPlayerState::StaticClass();
	PlayerControllerClass = ASkeletonInputController::StaticClass();
	//TileMap = ConstructorHelpers::FObjectFinder<UPaperTileMap>( TEXT( "PaperTileMap'/Game/Sprite_Sheets/MapTest.MapTest'" ) ).Object;
	TileMap = ConstructorHelpers::FObjectFinder<UPaperTileMap>( TEXT( "PaperTileMap'/Game/Sprite_Sheets/hyptosis_tile-art-batch-1_TileMap.hyptosis_tile-art-batch-1_TileMap'" ) ).Object;
}

void ASkeletonGameMode::StartPlay( )
{
	Super::StartPlay();

	UWorld* World = GetWorld( );

	if ( World )
	{
		Map = Cast<ASkeletonMap>( GetWorld( )->SpawnActor( ASkeletonMap::StaticClass( ) ) );
		Map->SetTileMap( TileMap );
	}
	ASkeletonCharacter* character = Cast<ASkeletonCharacter>( World->SpawnActor( ASkeletonCharacter::StaticClass( ) ) );
	Cast<ASkeletonInputController>( GetWorld()->GetFirstPlayerController() )->RegisterSkeleton( character );
	Cast<ACamera>( GetWorld( )->GetPawnIterator( )->Get( ) )->FollowSkeleton( character );
}

void ASkeletonGameMode::PostLogin( APlayerController* NewPlayer )
{

	
	Super::PostLogin( NewPlayer );
}