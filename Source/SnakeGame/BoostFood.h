// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food.h"
#include "Interactable.h"
#include "Kismet/GameplayStatics.h"
#include "Snake.h"
#include "BoostFood.generated.h"



/**
 * 
 */
UCLASS()
class SNAKEGAME_API ABoostFood : public AFood
{

	GENERATED_BODY()
    
    

    TSubclassOf<ABoostFood> BoostFoodClass;
	

    virtual void Interact(AActor* Interactor, bool bIsHead) override;
    
    virtual void Boost();
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<TSubclassOf<ABoostFood> > BoostFoodClasses;

    UPROPERTY()
    ASnake* SnakeIndex = nullptr;
private:
    UPROPERTY(EditDefaultsOnly)
    float BuffTime = 3.0f;

    FTimerHandle RecoveryTimerHandle;

    

};
