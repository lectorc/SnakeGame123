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
            Spawn();
            FoodSpawner->Boost();
            this->Destroy();
        }
    }
    
}


void ABoostFood::Spawn()
{
    int startX = -1430;
    int endX = 1430;
    int xLock = rand() % (endX - startX + 1) + startX; // Вычисление места спавна по x
    int startY = -1430;
    int endY = 1430;
    int yLock = rand() % (endY - startY + 1) + startY; //Вычисление места спавна Y
    FVector RandLocation(xLock, yLock, 0);
    FTransform RandTransform(RandLocation);
    Food = Cast<AFood>(UGameplayStatics::GetActorOfClass(GetWorld(), AFood::StaticClass()));
    if (Food == nullptr) return;
    if (Food->FoodClasses.Num() == 0) return;
    {
        TSubclassOf<AFood> RandomClass = Food->FoodClass = Food->FoodClasses[FMath::RandRange(0, Food->FoodClasses.Num() - 1)];
        GetWorld()->SpawnActor<AFood>(RandomClass, RandTransform);
    }
}

