// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PingPongBall.generated.h"
class USkeletalMeshComponent;
UCLASS()
class PINGPONG_API APingPongBall : public AActor
{
	GENERATED_BODY()
	
public:	
	APingPongBall();

protected:
    UPROPERTY(BlueprintReadWrite)
    bool EnemySite = true;
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComponent;
    UPROPERTY(VisibleDefaultsOnly)
    FVector SphereVelocity = FVector(6,-6,0);
    FVector SphereVelocityInvert = FVector(-6,6,0);
    
    virtual void Tick(float DeltaSeconds) override;
    virtual void BeginPlay() override;
    
private:
    
    UFUNCTION(BlueprintCallable)
    void ChangeVelocityY();
    
    void ChangeVelocityX();
  
    
    UFUNCTION()    
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
