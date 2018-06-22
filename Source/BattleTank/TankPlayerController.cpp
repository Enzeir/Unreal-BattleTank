// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick( DeltaSeconds );

	AimAtCrosshairs();


}


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Tank = GetControlledTank();

	if (Tank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is working for:  %s"), *(Tank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is not working"));
	}
}



ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimAtCrosshairs()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation; //OutParamater

	GetSightRayHitLocation( HitLocation );

	UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *(HitLocation.ToString()));

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const 
{
	OutHitLocation = FVector(1.0, 1.0, 1.0);
	// send a raycast from the camera
	//make the raycast go trough the crosshair
	//see if the raycast hits the landscape
	//if the raycast hits the landscape modify the value of HitLocation and return true

	//if the raycast does not hit the landscape return false

	return true;
}

