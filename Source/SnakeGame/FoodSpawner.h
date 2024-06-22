// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Snake.h"
#include "Kismet/GameplayStatics.h"
#include "FoodSpawner.generated.h"


class AFood;

UCLASS()
class SNAKEGAME_API AFoodSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodSpawner();

    UPROPERTY()
    AFood* Food = nullptr;
     
    UPROPERTY()
    ASnake* SnakeIndex = nullptr;

    UPROPERTY(EditDefaultsOnly)
    float SlowingTime = 3.0f;

    FTimerHandle RecoveryTimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable)
    void Spawn();
    
    UFUNCTION(BlueprintCallable)
    void Slowing();

    UFUNCTION(BlueprintCallable)
    void SlowingEnd();

    UFUNCTION(BlueprintCallable)
    void Boost();

    UFUNCTION(BlueprintCallable)
    void BoostEnd();
};
