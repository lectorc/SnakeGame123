// Fill out your copyright notice in the Description page of Project Settings.


#include "Snake.h"
#include "SnakeElementBase.h"
#include "Interactable.h"
// Sets default values

ASnake::ASnake()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    ElementSize = 100.f;
    MovementSpeed = 10.f;
    LastMoveDirection = EMovementDirection::DOWN;
}

// Called when the game starts or when spawned
void ASnake::BeginPlay()
{
    Super::BeginPlay();
    SetActorTickInterval(MovementSpeed);
    AddSnakeElement(5);
}

// Called every frame
void ASnake::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Move();
}

void ASnake::AddSnakeElement(int ElementsNum)
{
    for (int i = 0; i < ElementsNum; ++i)
    {
        FVector NewLocation(SnakeElements.Num() * ElementSize, 0, 0);
        FTransform NewTransform(NewLocation);
        ASnakeElementBase* NewSnakeElem = GetWorld()->SpawnActor<ASnakeElementBase>(SnakeElementClass, NewTransform);
        NewSnakeElem->SnakeOwner = this;
        int32 ElemIndex = SnakeElements.Add(NewSnakeElem);
        if (ElemIndex == 0)
        {
            NewSnakeElem->SetFirstElementType();    
        }
    }
}

void ASnake::Move()
{
    FVector MovementVector(ForceInitToZero);
    switch (LastMoveDirection)
    {
    case EMovementDirection::UP:
        MovementVector.X += MovementSpeed;
        break;
    case EMovementDirection::DOWN:
        MovementVector.X -= MovementSpeed;
        break;
    case EMovementDirection::LEFT :
        MovementVector.Y += MovementSpeed;
        break;
    case EMovementDirection::RIGHT:
        MovementVector.Y -= MovementSpeed;
        break;  
    }
     //AddActorWorldOffset(MovementVector);
    SnakeElements[0]->ToggleCollision();
    
    for (int i = SnakeElements.Num() - 1; i > 0; i--)
    {
        auto CurrentElement = SnakeElements[i];
        auto PrevElement = SnakeElements[i - 1];
        FVector PrevLocation = PrevElement->GetActorLocation();
        CurrentElement->SetActorLocation(PrevLocation);

    }
    SnakeElements[0]->AddActorWorldOffset(MovementVector);
    SnakeElements[0]->ToggleCollision();
}

void ASnake::SnakeElementOverlap(ASnakeElementBase* OverlappedElement, AActor* Other)
{
    if (IsValid(OverlappedElement))
    {
        int32 ElemIndex;
        SnakeElements.Find(OverlappedElement, ElemIndex);
        bool bIsFirst = ElemIndex == 0;
        IInteractable* InteractableInterface = Cast<IInteractable>(Other);
        if(InteractableInterface)
        {
            InteractableInterface->Interact(this, bIsFirst);
        }
    }
}
