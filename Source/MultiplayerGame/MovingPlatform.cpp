// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
	
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector ActorLocation = GetActorLocation();
		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JourneyTraveled = (ActorLocation - GlobalStartLocation).Size();
		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();

		if (JourneyTraveled >= JourneyLength)
		{
			FVector Swap = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
		}

		ActorLocation += MoveSpeed * DeltaTime * Direction;
		
		SetActorLocation(ActorLocation);
	}
}
