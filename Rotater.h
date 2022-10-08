// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math/UnrealMathUtility.h"
#include "Rotater.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API URotater : public UActorComponent
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	URotater();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void SetShouldRotate(bool ShouldRotate);
private:
	UPROPERTY(EditAnywhere)
		FRotator MoveOffSet;

	UPROPERTY(EditAnywhere)
		float Movetime = 100;	
	UPROPERTY(EditAnywhere)
		float speed = 2;

	bool ShouldRotate = false;

	FRotator OriginalRotation;
		
};
