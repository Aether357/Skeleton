
#include "Skeleton.h"
#include "SkeletonCharacter.h"
#include "SimpleMovementComponent.h"
#include "CreatureCollectionActor.h"
#include "CollisionCreatureActor.h"

ASkeletonCharacter::ASkeletonCharacter( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer )
{
	PrimaryActorTick.bCanEverTick = true;

	/*
	ConstructorHelpers::FObjectFinder<UMaterial> SkeletonFinder( TEXT( "Material'/Game/Characters/character_img_Mat.character_img_Mat'" ) );

	this->AddBluePrintCollectionClipData(  )
	creature_mesh->SetMaterial( 0, SkeletonFinder.Object );
	creature_filename = "character_data.zip";
	creature_mesh->SetCollisionEnabled( ECollisionEnabled::QueryAndPhysics );
	creature_mesh->SetEnableGravity( false );

	
	this->SetActorRelativeScale3D( FVector( 2.5f, 1.0f, 2.5f ) );



	MovementComponent = ObjectInitializer.CreateDefaultSubobject<USimpleMovementComponent>( this, "MovementComp" );


	RootComponent = CollisionComponent;
	*/
	MovementComponent = ObjectInitializer.CreateDefaultSubobject<USimpleMovementComponent>( this, "MovementComp" );
	//SkeletonClips = ObjectInitializer.CreateDefaultSubobject<ACreatureCollectionActor>( this, "SkeletonClips" );
	//creature_mesh = ObjectInitializer.CreateDefaultSubobject<UCustomProceduralMeshComponent>( this, "Mesh" );
	
	ConstructorHelpers::FObjectFinder<UBlueprint> RunningLeftBlueprint( TEXT( "Blueprint'/Game/Characters/Skeleton/RunningLeft_Skeleton.RunningLeft_Skeleton'" ) );
	if ( GEngine && RunningLeftBlueprint.Object )
	{
		if ( GetWorld() )
		{
			ACollisionCreatureActor* actor = Cast<ACollisionCreatureActor>( GetWorld()->SpawnActor( Cast<UClass>( RunningLeftBlueprint.Object->GeneratedClass ) ) );
			//GEngine->AddOnScreenDebugMessage( -1, 5.f, FColor::Red, TEXT( "Spawned the Creature" ) );
			this->RootComponent = actor->GetRootComponent();
			actor->creature_debug_draw = true;
			actor->SetActorEnableCollision( true );
		}
		// create an instance of this
		//this->creature_mesh = Left.Object->creature_mesh;
	}

	//this->creature_mesh = Left.Object->creature_mesh;
}

// Called when the game starts or when spawned
void ASkeletonCharacter::BeginPlay()
{	
	Super::BeginPlay();
	/*
	FVector loc = this->GetActorLocation();
	loc.Y += 2.0f;
	this->SetActorLocation( loc );*/
}

// Called every frame
void ASkeletonCharacter::Tick( float DeltaSeconds )
{
	Super::Tick( DeltaSeconds );
}

void ASkeletonCharacter::MoveHorizontal( float Scale )
{
	MovementComponent->SetXVelocity( Scale );
}

void ASkeletonCharacter::MoveVertical( float Scale )
{
	MovementComponent->SetZVelocity( Scale );
}