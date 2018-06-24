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

	UE_LOG(LogTemp, Warning, TEXT("Hit location at: %s"), *HitLocation.ToString());

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const 
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	
	FVector LookDirection;
	FVector CameraLocation;
	if (GetLookDirection(ScreenLocation, LookDirection, CameraLocation))
	{
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	// send a raycast from the camera
	//make the raycast go trough the crosshair
	//see if the raycast hits the landscape
	//if the raycast hits the landscape modify the value of HitLocation and return true

	//if the raycast does not hit the landscape return false

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection, FVector & CameraLocation) const
{

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraLocation,
		LookDirection
	);

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{


	FVector CameraLocation = PlayerCameraManager->GetCameraLocation();

	FHitResult HitResult;

	FVector EndLocation = CameraLocation + (LookDirection * LineTraceRange);


	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		CameraLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;

		return true;
	}
	HitLocation = FVector(0, 0, 0);
	return false; 


}

