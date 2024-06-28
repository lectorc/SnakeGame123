// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food.h"
#include "Interactable.h"
#include "Snake.h"
#include "Kismet/GameplayStatics.h"
#include "SlowingFood.generated.h"


/**
 * 
 */
UCLASS()
class SNAKEGAME_API ASlowingFood : public AFood
{
	GENERATED_BODY()

    

    TSubclassOf<ASlowingFood> SlowingFoodClass;

    UPROPERTY()
    AFood* Food = nullptr;

    UPROPERTY(EditDefaultsOnly)
    float SlowingTime = 3.0f;

    UFUNCTION(BlueprintCallable)
    void Spawn();

    virtual void Interact(AActor* Interactor, bool bIsHead) override;
public:

    UPROPERTY()
    ASnake* SnakeIndex = nullptr;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<TSubclassOf<ASlowingFood> > SlowingFoodClasses;

    FTimerHandle RecoveryTimerHandle;
};

