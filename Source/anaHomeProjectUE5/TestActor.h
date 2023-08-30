// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class ANAHOMEPROJECTUE5_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="MovingPlatform")
	FVector PlatformVelocity = FVector(0,100,0);

	UPROPERTY(EditAnywhere, Category="MovingPlatform")
	float MoveDistance = 100;

	FVector StartLocation;

};