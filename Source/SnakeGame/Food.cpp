
// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "Snake.h"
#include "SlowingFood.h"
#include "BoostFood.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFood::Interact(AActor* Interactor, bool bIsHead)
{
    if (bIsHead)
    {
        auto Snake = Cast<ASnake>(Interactor);
        if (IsValid(Snake))
        {
            Snake->AddSnakeElement(1);
        }
    }
}

void AFood::Spawn()
{
    int startX = -1430;
    int endX = 1430;
    int xLock = rand() % (endX - startX + 1) + startX; // Вычисление места спавна по x
    int startY = -1430;
    int endY = 1430;
    int yLock = rand() % (endY - startY + 1) + startY; //Вычисление места спавна Y
    FVector RandLocation(xLock, yLock, 0);
    FTransform RandTransform(RandLocation);
    if (FoodClasses.Num() == 0) return;
    {
        TSubclassOf<AFood> RandomClass = FoodClass = FoodClasses[FMath::RandRange(0, FoodClasses.Num() - 1)];
        GetWorld()->SpawnActor<AFood>(RandomClass, RandTransform);
        this->Destroy();
    }
}





