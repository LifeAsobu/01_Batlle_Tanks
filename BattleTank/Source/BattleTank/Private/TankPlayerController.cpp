

#include "Public/TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not Possing the tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possing: %s"), *ControlledTank->GetName())
	}
	//UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"))
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
//	UE_LOG(LogTemp, Warning, TEXT("Player Controller Ticking"))

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }	
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
	}

}
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation,ViewportSizeY * CrossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), ScreenLocation);
	return true;
}
