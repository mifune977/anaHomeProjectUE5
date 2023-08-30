// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	FString Name =  GetName();

	UE_LOG(LogTemp, Display, TEXT("Begin Play: %s"), *Name);

}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}

void ATestActor::MovePlatform(float DeltaTime)
{
	//Move platform forwards
		//get current location
	FVector CurrentLocation = GetActorLocation();
		//add vector to that location
	CurrentLocation = CurrentLocation + (PlatformVelocity* DeltaTime);
		//set the location
	SetActorLocation(CurrentLocation);
	//send platform back if gone too far
		//check how far we've moved
	float DistancedMoved = FVector::Dist(StartLocation, CurrentLocation);
		//reverse direction of motion if gone too far

	if (DistancedMoved > MoveDistance)
	{
		float OverShoot = DistancedMoved - MoveDistance;
		FString Name =  GetName();
		UE_LOG(LogTemp, Display, TEXT("%s Platform OverShot by: %f"), *Name,  OverShoot);
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation  + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation); 
		PlatformVelocity = -PlatformVelocity;
		
	}
}
void ATestActor::RotatePlatform(float DeltaTIme)
{
	FString Name = GetName();
	UE_LOG(LogTemp, Display, TEXT("%s rotating..."), *GetName());
}