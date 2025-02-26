// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Engine/World.h"
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
	
public:
	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;


private:
	
	ATank* GetControlledTank() const;

	void AimAtCrosshairs();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const ;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection, FVector& CameraLocation) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

};

