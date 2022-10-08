// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Rotater.h"
#include "Triggerarea2.generated.h"



UCLASS()
class CRYPTRAIDER_API UTriggerarea2 : public UBoxComponent
{
	GENERATED_BODY()


public:
	// Sets default values for this component's properties
	UTriggerarea2();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
		void SetRotate(URotater* Rotate);
private:
	UPROPERTY(EditAnywhere)
		FName AcceptedTag;

	URotater* Rotate;

	AActor* GetAcceptableActor() const;
};
