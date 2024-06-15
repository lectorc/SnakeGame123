// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowingFood.h"
#include "Thread"
#include "chrono"
#include "Snake.h"
 

void ASlowingFood::Spawn()
{
}

void ASlowingFood::Slowing()
{
    SnakeIndex = Cast<ASnake>(UGameplayStatics::GetActorOfClass(GetWorld(), ASnake::StaticClass()));
    if (SnakeIndex == nullptr) return;
    SnakeIndex->MovementSpeed = 10.f;
}


void ASlowingFood::Interact(AActor* Interactor, bool bIsHead)
{
    if (bIsHead)
    {
        auto Snake = Cast<ASnake>(Interactor);
        if (IsValid(Snake))
        {
            Snake->MovementSpeed = 5.f;
            Snake->AddSnakeElement(1);
            GetWorldTimerManager().SetTimer(RecoveryTimerHandle, this, &ASlowingFood::Slowing, 0.f, false, -1);
            this->Destroy();


        }
    }
}
