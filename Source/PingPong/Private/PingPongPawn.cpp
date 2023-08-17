#include "PingPongPawn.h"

#include "PingPongPlayerController.h"


APingPongPawn::APingPongPawn()
{
    PrimaryActorTick.bCanEverTick = true;

}

void APingPongPawn::BeginPlay()
{
    Super::BeginPlay();

    
}

void APingPongPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
 
    if(Direction == EDirection::Stop) return;
    FVector BlockWallUP(710,-1170,112.000687);
    FVector BlockWallDown(-800,-1170,112.000687);

    FVector Speed = FVector(0);
  
    switch (Direction)
    {
        case EDirection::Up:
        {
           if(GetActorLocation().X>710){ SetActorLocation(BlockWallUP);break;} // ограничение в движении
            Speed = FVector(SpeedValue, 0, 0);
            break;
        }
        case EDirection::Down:
        {
            if(GetActorLocation().X<-800){ SetActorLocation(BlockWallDown);break;}
            Speed = FVector(-SpeedValue, 0, 0);
            break;
        }
    }

    AddActorLocalOffset(Speed);
}

