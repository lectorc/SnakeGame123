// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowingFood.h"
#include "Snake.h"
#include "Thread"
#include "chrono"


ASnake::ASnake()
{
    MovementSpeed = 5;
    ElementSize = 200;
    using namespace std::this_thread;
    using namespace std::chrono;
    sleep_for(seconds(1));
}
