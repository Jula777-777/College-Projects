// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "SwingDoor.h"
#include "CoinC.generated.h"

UCLASS()
class SHELTEMASSIGNMENT3_API ACoinC : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UBoxComponent* CollisionMesh;

	UPROPERTY()
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Assignment")
	ASwingDoor* Door = nullptr;

	bool visible = true;

	// Sets default values for this actor's properties
	ACoinC();

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
