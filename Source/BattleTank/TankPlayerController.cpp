// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Tank = GetControlledTank();

	if (Tank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("GetControlledTank is working for:  %s"), *(Tank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("GetControlledTank is not working"));
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}



ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
