// Fill out your copyright notice in the Description page of Project Settings.


#include "PingPongBall.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMeshSocket.h"

APingPongBall::APingPongBall()
{
MeshComponent=CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
    SetRootComponent(MeshComponent);
    MeshComponent->OnComponentHit.AddDynamic(this, &APingPongBall::OnHit);
}

void APingPongBall::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    AddActorLocalOffset(SphereVelocity,true);
}

void APingPongBall::BeginPlay()
{
    Super::BeginPlay();
   if(EnemySite){SphereVelocity=SphereVelocityInvert;}
}



void APingPongBall::ChangeVelocityX()
{
    SphereVelocity=FVector(-SphereVelocity.X,SphereVelocity.Y,SphereVelocity.Z);
}
void APingPongBall::ChangeVelocityY()
{
    SphereVelocity=FVector(-SphereVelocity.X,-SphereVelocity.Y,SphereVelocity.Z);
}

void APingPongBall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
    const FHitResult& Hit)
{
    if(Hit.Normal.X!=0) ChangeVelocityX();
    if(Hit.Normal.Y!=0) ChangeVelocityY();
 
    
}
