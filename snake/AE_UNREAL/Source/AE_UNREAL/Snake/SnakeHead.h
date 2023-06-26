#pragma once

#include "CoreMinimal.h"
#include "SnakePart.h"
#include "SnakeHead.generated.h"

UCLASS()
class AE_UNREAL_API ASnakeHead : public ASnakePart
{
	GENERATED_BODY()
	
public:	
	ASnakeHead();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void LeftMove(float _Value);

	UFUNCTION(BlueprintCallable)
	void RightMove(float _Value);

	UFUNCTION(BlueprintCallable)
	void UpMove(float _Value);

	UFUNCTION(BlueprintCallable)
	void DownMove(float _Value);

	UFUNCTION(BlueprintCallable)
		void LeftAction();

	UFUNCTION(BlueprintCallable)
		void RightAction();

	UFUNCTION(BlueprintCallable)
		void UpAction();

	UFUNCTION(BlueprintCallable)
		void DownAction();

};
