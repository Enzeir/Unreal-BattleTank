// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	ATank* AITank = GetControlledTank();

	ATank* PlayerTank = GetPlayerTank();

	if (AITank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController is working for:  %s"), *(AITank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cant find the controlled tank."));
	}

	if (PlayerTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player's tank is: %s"), *(PlayerTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player's tank not found."));
	}


}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto Tank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!Tank)
	{
		return nullptr;
	}
	return Cast<ATank>(Tank);
}
