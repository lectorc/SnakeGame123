// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnBase.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
APlayerPawnBase::APlayerPawnBase()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
    RootComponent = PawnCamera;
}



inline void APlayerPawnBase::BeginPlay()
{
    Super::BeginPlay();
    SetActorRotation(FRotator(-90, 0, 0));
    CreateSnakeActor();
    
    
   
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
    Snake = Cast<ASnake>(UGameplayStatics::GetActorOfClass(GetWorld(), ASnake::StaticClass()));
    if (Snake == nullptr) return;
    if (Snake->canMove == true)
    {
        if (IsValid(SnakeActor))
        {
            if (value > 0 && SnakeActor->LastMoveDirection != EMovementDirection::DOWN)
            {
                SnakeActor->LastMoveDirection = EMovementDirection::UP;
                Snake->canMove = false;
            }
            else if (value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::UP)
            {
                SnakeActor->LastMoveDirection = EMovementDirection::DOWN;
                Snake->canMove = false;
            }

        }
    }
}

void APlayerPawnBase::HandlePlayerHorizontalInput(float value)
{
    if (IsValid(SnakeActor))
    {
        Snake = Cast<ASnake>(UGameplayStatics::GetActorOfClass(GetWorld(), ASnake::StaticClass()));
        if (Snake == nullptr) return;
        if (Snake->canMove == true)
        {
            if (value > 0 && SnakeActor->LastMoveDirection != EMovementDirection::LEFT)
            {
                SnakeActor->LastMoveDirection = EMovementDirection::RIGHT;
                Snake->canMove = false;
            }
            else if (value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::RIGHT)
            {
                SnakeActor->LastMoveDirection = EMovementDirection::LEFT;
                Snake->canMove = false;
            }
        }
    }
}

