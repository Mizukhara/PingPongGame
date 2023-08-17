#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PingPongPlayerController.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum EDirection
{
    Down UMETA(DisplayName = "Down"),
    Up      UMETA(DisplayName = "Up"),
    Stop   UMETA(DisplayName = "Stop")
};

UCLASS()
class PINGPONG_API APingPongPlayerController : public APlayerController
{
    GENERATED_BODY()
    
    virtual void SetupInputComponent() override;

private:
      
    UFUNCTION()
    void StartMoveUp();
    UFUNCTION()
    void StopMoveUp();
    UFUNCTION()
    void StartMoveDown();
    UFUNCTION()
    void StopMoveDown();

    
};
