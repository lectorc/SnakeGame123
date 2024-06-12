// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowingFood.h"
#include "Thread"
#include "chrono"
#include "Snake.h"
 

void ASlowingFood::Spawn()
{
}


void ASlowingFood::Interact(AActor* Interactor, bool bIsHead)
{
    if (bIsHead)
    {
        auto Snake = Cast<ASnake>(Interactor);
        if (IsValid(Snake))
        {
            Snake->MovementSpeed = 10.f;
            Snake->AddSnakeElement(1);
            this->Destroy();
            int startX = -1430;
            int endX = 1430;
            int xLock = rand() % (endX - startX + 1) + startX; // Вычисление места спавна по x
            int startY = -1430;
            int endY = 1430;
            int yLock = rand() % (endY - startY + 1) + startY; //Вычисление места спавна Y
            FVector RandLocation(xLock, yLock, 0);
            FTransform RandTransform(RandLocation);
            if (SlowingFoodClasses.Num() == 0) return;
            {
                TSubclassOf<ASlowingFood> RandomClass = SlowingFoodClass = SlowingFoodClasses[FMath::RandRange(0, SlowingFoodClasses.Num() - 1)];
                GetWorld()->SpawnActor<ASlowingFood>(RandomClass, RandTransform);
                
            }
        }
    }
}
