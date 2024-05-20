// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawnBase.generated.h"


class UCameraComponent;
class ASnake;

UCLASS()
class SNAKEGAME_API APlayerPawnBase : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
	APlayerPawnBase();

    UPROPERTY(BlueprintReadWrite) 
    UCameraComponent* PawnCamera;

    UPROPERTY(BlueprintReadWrite)
    ASnake* SnakeActor;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ASnake> SnakeActorClass;
protected:
	// Called when the game starts or when spawned
    // Called when the game starts or when spawned
    virtual void BeginPlay() override
    {
        Super::BeginPlay();
        SetActorRotation(FRotator(-90, 0, 0));
    }

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void CreateSnakeActor()
    {
        SnakeActor = GetWorld()->SpawnActor<ASnake>(SnakeActorClass, FTransform());
    }

    UFUNCTION()
    void HandlePlayerVerticalInput(float value);

    UFUNCTION()
    void HandlePlayerHorizontalInput(float value);
};
