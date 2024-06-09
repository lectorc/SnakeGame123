// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food.h"
#include "SlowingFood.generated.h"

/**
 * 
 */
UCLASS()
class SNAKEGAME_API ASlowingFood : public AFood
{
	GENERATED_BODY()
	

    UFUNCTION(BlueprintCallable)
    virtual void Slowing();
};

