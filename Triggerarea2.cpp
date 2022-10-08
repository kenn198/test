// Fill out your copyright notice in the Description page of Project Settings.


#include "Triggerarea2.h"


UTriggerarea2::UTriggerarea2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UTriggerarea2::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UTriggerarea2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AActor* Actor = GetAcceptableActor();
	if (Actor != nullptr) {
		UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
		if (Component != nullptr)
		{
			/*Component->SetSimulatePhysics(false);*/
			Rotate->SetShouldRotate(true);
			Actor->SetActorEnableCollision(false); /*disabled the key from being picked up*/
		}
		//Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
	}
	else
	{
		Rotate->SetShouldRotate(false);
	}
}
AActor* UTriggerarea2:: GetAcceptableActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag(AcceptedTag))
		{
			return Actor;
		}
	}
	return nullptr;
}
void UTriggerarea2::SetRotate(URotater* NewRotate)
{
	Rotate = NewRotate;
}
