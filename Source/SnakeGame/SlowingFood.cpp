// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowingFood.h"
#include "Thread"
#include "chrono"
#include "Snake.h"
 




void ASlowingFood::Interact(AActor* Interactor, bool bIsHead)
{
    if (bIsHead)
    {
        auto Snake = Cast<ASnake>(Interactor);
        if (IsValid(Snake))
        {
            Snake->AddSnakeElement(1);
            FoodSpawner = Cast<AFoodSpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), AFoodSpawner::StaticClass()));
            FoodSpawner->Spawn();
            FoodSpawner->Slowing();
            this->Destroy();
        }
    }
}
