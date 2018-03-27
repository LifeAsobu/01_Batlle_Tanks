

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

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}