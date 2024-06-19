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
            Snake->MovementSpeed =  30.f;
            Snake->AddSnakeElement(1);
            GetWorldTimerManager().SetTimer(RecoveryTimerHandle, this, &ABoostFood::Boost, 1.f, false, -1);
            
            
            
           
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
