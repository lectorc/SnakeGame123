// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Snake.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerPawnBase.generated.h"




class UCameraComponent;


UCLASS()
class SNAKEGAME_API APlayerPawnBase : public APawn
{
    GENERATED_BODY()

public:
    
	APlayerPawnBase();

    UPROPERTY(BlueprintReadWrite) 
    UCameraComponent* PawnCamera;

    UPROPERTY(BlueprintReadWrite)
    ASnake* SnakeActor;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ASnake> SnakeActorClass;
protected:
    virtual void BeginPlay() override;

public:

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
