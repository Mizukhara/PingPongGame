// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PingPongPlayerController.h"
#include "GameFramework/Pawn.h"
#include "PingPongPawn.generated.h"

UCLASS()
class PINGPONG_API APingPongPawn : public APawn
{
    GENERATED_BODY()

public:
    APingPongPawn();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void SetDirection(EDirection Value) { Direction = Value;};
    EDirection GetDirection() const { return Direction; }

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SpeedValue = 1;

private:
    EDirection Direction = EDirection::Stop;
};
