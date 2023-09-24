// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwingDoor.generated.h"

UCLASS()
class SHELTEMASSIGNMENT3_API ASwingDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwingDoor();

	UPROPERTY()
	UStaticMeshComponent* VisualMesh;

	bool shouldOpen = false;
	int numberofTicks = 0;

	UFUNCTION()
	void open();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
