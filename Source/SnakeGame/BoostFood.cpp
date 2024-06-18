// Fill out your copyright notice in the Description page of Project Settings.


#include "BoostFood.h"
#include "Snake.h"
#include <windows.h> 

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
    if (BoostFoodClasses.Num() == 0) return;
    {
        TSubclassOf<ABoostFood> RandomClass = BoostFoodClass = BoostFoodClasses[FMath::RandRange(0, BoostFoodClasses.Num() - 1)];
        GetWorld()->SpawnActor<ABoostFood>(RandomClass, RandTransform);
        this->Destroy();
        

    }
}

void ABoostFood::Interact(AActor* Interactor, bool bIsHead)
{
    if (bIsHead)
    {
        auto Snake = Cast<ASnake>(Interactor);
        if (IsValid(Snake))
        {
            Snake->MovementSpeed =  30.f;
            Snake->AddSnakeElement(1);
            GetWorldTimerManager().SetTimer(RecoveryTimerHandle, this, &ABoostFood::Boost, 1.f, false, -1);
            Spawn();
            
            
           
        }
    }
    
}

void ABoostFood::Boost()
{
    SnakeIndex = Cast<ASnake>(UGameplayStatics::GetActorOfClass(GetWorld(), ASnake::StaticClass()));
    if (SnakeIndex == nullptr) return;
    SnakeIndex->MovementSpeed = 10.f;
    SnakeIndex->SetActorTickInterval(1 / SnakeIndex->MovementSpeed);
}
