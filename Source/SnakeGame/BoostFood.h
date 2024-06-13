// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food.h"
#include "Interactable.h"
#include "BoostFood.generated.h"


/**
 * 
 */
UCLASS()
class SNAKEGAME_API ABoostFood : public AFood
{

	GENERATED_BODY()
    TSubclassOf<ABoostFood> BoostFoodClass;
	
    virtual void Spawn() override;

    virtual void Interact(AActor* Interactor, bool bIsHead) override;
    
    virtual void Boost(AActor* Interactor);
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<TSubclassOf<ABoostFood> > BoostFoodClasses;
private:
    UPROPERTY(EditDefaultsOnly)
    float BuffTime = 3.0f;

    FTimerHandle RecoveryTimerHandle;

};
