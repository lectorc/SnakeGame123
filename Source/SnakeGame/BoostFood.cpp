// Fill out your copyright notice in the Description page of Project Settings.


#include "BoostFood.h"
#include "Snake.h"
#include <windows.h> 



void ABoostFood::Interact(AActor* Interactor, bool bIsHead)
{
    if (bIsHead)
    {
        auto Snake = Cast<ASnake>(Interactor);
        if (IsValid(Snake))
        {
            Snake->AddSnakeElement(1);
            FoodSpawner = Cast<AFoodSpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), AFoodSpawner::StaticClass()));
            FoodSpawner->Spawn();
            FoodSpawner->Boost();
            this->Destroy();
        }
    }
    
}

