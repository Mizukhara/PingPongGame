// Fill out your copyright notice in the Description page of Project Settings.


#include "PingPongPlayerController.h"

#include "PingPongPawn.h"

void APingPongPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("MoveUp", IE_Pressed, this, &APingPongPlayerController::StartMoveUp);
    InputComponent->BindAction("MoveUp", IE_Released, this, &APingPongPlayerController::StopMoveUp);
    InputComponent->BindAction("MoveDown", IE_Pressed, this, &APingPongPlayerController::StartMoveDown);
    InputComponent->BindAction("MoveDown", IE_Released, this, &APingPongPlayerController::StopMoveDown);
}

void APingPongPlayerController::StartMoveUp()
{
    if(!GetPawn()) return;
    if(APingPongPawn* PingPongPawn = Cast<APingPongPawn>(GetPawn()))
    {
        PingPongPawn->SetDirection(EDirection::Up);
    }
}

void APingPongPlayerController::StopMoveUp()
{
    if(!GetPawn()) return;
    
    APingPongPawn* PingPongPawn = Cast<APingPongPawn>(GetPawn());
    if(PingPongPawn && PingPongPawn->GetDirection() != EDirection::Down)
    {
        PingPongPawn->SetDirection(EDirection::Stop);
    }
}

void APingPongPlayerController::StartMoveDown()
{
    if(!GetPawn()) return;
    
    if(APingPongPawn* PingPongPawn = Cast<APingPongPawn>(GetPawn()))
    {
        PingPongPawn->SetDirection(EDirection::Down);
    }
}

void APingPongPlayerController::StopMoveDown()
{
    if(!GetPawn()) return;

    APingPongPawn* PingPongPawn = Cast<APingPongPawn>(GetPawn());
    if(PingPongPawn && PingPongPawn->GetDirection() != EDirection::Up)
    {
        PingPongPawn->SetDirection(EDirection::Stop);
    }
}
