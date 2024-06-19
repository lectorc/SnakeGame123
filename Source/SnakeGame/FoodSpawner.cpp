// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodSpawner.h"
#include "Food.h"

// Sets default values
AFoodSpawner::AFoodSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFoodSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFoodSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFoodSpawner::Spawn()
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
        this->Destroy();
    }
}

