// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnBase.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"


// Sets default values
APlayerPawnBase::APlayerPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
        RootComponent = PawnCamera;
}



void APlayerPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawnBase::HandlePlayerHorizontalInput);
    PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawnBase::HandlePlayerVerticalInput);

}

void APlayerPawnBase::HandlePlayerVerticalInput(float value)
{
    if (IsValid(SnakeActor))
    {
        if (value > 0 && SnakeActor->LastMoveDirection!=EMovementDirection::DOWN)
        {
            SnakeActor->LastMoveDirection = EMovementDirection::UP;
        }
        else if (value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::UP)
        {
            SnakeActor->LastMoveDirection = EMovementDirection::DOWN;
        }
        
    }
}

void APlayerPawnBase::HandlePlayerHorizontalInput(float value)
{
    if (IsValid(SnakeActor))
    {
        if (value > 0 && SnakeActor->LastMoveDirection != EMovementDirection::LEFT)
        {
            SnakeActor->LastMoveDirection = EMovementDirection::RIGHT;
        }
        else if (value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::RIGHT)
        {
            SnakeActor->LastMoveDirection = EMovementDirection::LEFT;
        }
    }
}

