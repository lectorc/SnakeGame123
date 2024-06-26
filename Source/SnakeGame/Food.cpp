
// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "Snake.h"
#include "SlowingFood.h"
#include "FoodSpawner.h"
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
            FoodSpawner = Cast<AFoodSpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), AFoodSpawner::StaticClass()));
            FoodSpawner->Spawn();
            this->Destroy();
        }
    }
}







