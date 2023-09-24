// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Engine/TriggerBox.h"
#include "Engine/PointLight.h"
#include "Lights.generated.h"

UCLASS()
class SHELTEMASSIGNMENT3_API ALights : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY()
	UBoxComponent* TriggerBox;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Triggered Events")
	TArray<APointLight*> Lights;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Triggered Events")
	bool PlayEndSound;

	// Sets default values for this actor's properties
	ALights();

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
