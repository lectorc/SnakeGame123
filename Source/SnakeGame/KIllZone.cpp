// Fill out your copyright notice in the Description page of Project Settings.


#include "KIllZone.h"

// Sets default values
AKIllZone::AKIllZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKIllZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKIllZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKIllZone::Interact(AActor* Interactor, bool bIsHead)
{
    
        if (bIsHead)
        {
            auto Snake = Cast<ASnake>(Interactor);
            if (IsValid(Snake))
            {

                Snake->Destroy();
                SnakeDestroyed();
            }
        }
}

void AKIllZone::SnakeDestroyed_Implementation()
{
    
}


