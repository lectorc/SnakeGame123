// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food.h"
#include "Interactable.h"
#include "SlowingFood.generated.h"


/**
 * 
 */
UCLASS()
class SNAKEGAME_API ASlowingFood : public AFood
{
	GENERATED_BODY()

    TSubclassOf<ASlowingFood> SlowingFoodClass;

    virtual void Spawn() override;

    virtual void Interact(AActor* Interactor, bool bIsHead) override;
public:

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<TSubclassOf<ASlowingFood> > SlowingFoodClasses;
};

