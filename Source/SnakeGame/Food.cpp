
// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "Snake.h"

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
    Spawn();
	
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
            Spawn();
            Snake->AddSnakeElement(1);
        }
    }
}

void AFood::Spawn()
{
    int startX = -2300;
    int endX = 2320;
    int xLock = rand() % (endX - startX + 1) + startX; // Вычисление места спавна по x
    int startY = -2310;
    int endY = 2310;
    int yLock = rand() % (endY - startY + 1) + startY; //Вычисление места спавна Y
    FVector RandLocation(xLock, yLock, 0);
    FTransform RandTransform(RandLocation);
    AFood* FoodSpawn = GetWorld()->SpawnActor<AFood>(FoodClass, RandTransform);

}

