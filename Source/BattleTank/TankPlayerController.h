// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;
	
	ATank* GetControlledTank() const;

	void AimAtCrosshairs();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const ;
};