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
	
	if (ShouldPlatformReturn())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation  + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation); 
		PlatformVelocity = -PlatformVelocity;	
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity* DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

void ATestActor::RotatePlatform(float DeltaTIme)
{
	UE_LOG(LogTemp, Display, TEXT("%s rotating..."), *GetName());
}

bool ATestActor::ShouldPlatformReturn() const
{

	return GetDistancedMoved() > MoveDistance;	
}
float ATestActor::GetDistancedMoved()const 
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
