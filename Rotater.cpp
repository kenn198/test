// Fill out your copyright notice in the Description page of Project Settings.


#include "Rotater.h"

// Sets default values for this component's properties
URotater::URotater()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotater::BeginPlay()
{
	Super::BeginPlay();

	OriginalRotation = GetOwner()->GetActorRotation();
	
}


// Called every frame
void URotater::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FRotator TargetRotation = OriginalRotation;

	if (ShouldRotate == true)
	{
		TargetRotation = OriginalRotation + MoveOffSet;
		FRotator CurrentRotation = GetOwner()->GetActorRotation();
		FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, speed);
		GetOwner()->SetActorRotation(NewRotation);
	}


}
void URotater::SetShouldRotate(bool NewShouldRotate)
{
	ShouldRotate = NewShouldRotate;

}

