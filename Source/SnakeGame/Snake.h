// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Snake.generated.h"



class ASnakeElementBase;

UENUM()
enum class EMovementDirection
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

UCLASS()
class SNAKEGAME_API ASnake : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnake();

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ASnakeElementBase> SnakeElementClass;

    UPROPERTY(EditDefaultsOnly)
    float ElementSize;

    UPROPERTY(EditDefaultsOnly)
    float MovementSpeed;

    UPROPERTY()
    TArray<ASnakeElementBase*> SnakeElements;

    UPROPERTY()
    EMovementDirection LastMoveDirection;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    void AddSnakeElement(int ElementsNum = 1);
    
    void Move()
    {
        FVector MovementVector(ForceInitToZero);
        MovementSpeed = ElementSize;
        switch (LastMoveDirection)
        {
        case EMovementDirection::UP:
            MovementVector.X += MovementSpeed;
            break;
        case EMovementDirection::DOWN:
            MovementVector.X -= MovementSpeed;
            break;
        case EMovementDirection::LEFT:
            MovementVector.Y += MovementSpeed;
            break;
        case EMovementDirection::RIGHT:
            MovementVector.Y -= MovementSpeed;
            break;
        }
        //AddActorWorldOffset(MovementVector);

        for (int i = SnakeElements.Num() - 1; i > 0; i--)
        {
            auto CurrentElement = SnakeElements[i];
            auto PrevElement = SnakeElements[i - 1];
            FVector PrevLocation = PrevElement->GetActorLocation();
            CurrentElement->SetActorLocation(PrevLocation);

        }

        SnakeElements[0]->AddActorWorldOffset(MovementVector);
    }
};

