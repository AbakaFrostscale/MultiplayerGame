// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERGAME_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 10;

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (MakeEditWidget = true))
	FVector TargetLocation;
private:
	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;
};
