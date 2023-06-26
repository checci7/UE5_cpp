#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakePart.generated.h"

UCLASS()
class AE_UNREAL_API ASnakePart : public AActor
{
	GENERATED_BODY()
	
public:	
	ASnakePart();

	class ASnakeGameMode* GetSnakeGameMode();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
