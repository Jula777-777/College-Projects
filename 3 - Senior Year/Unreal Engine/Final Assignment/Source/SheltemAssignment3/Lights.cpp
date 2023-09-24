// Fill out your copyright notice in the Description page of Project Settings.


#include "Lights.h"

#include "Kismet/GameplayStatics.h"


// Sets default values
ALights::ALights()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	SetRootComponent(TriggerBox);
	TriggerBox->SetBoxExtent({ 70.0f, 70.0f, 80.0f });
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ALights::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ALights::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALights::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALights::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	for (APointLight* PointLight : Lights)
	{
		PointLight->GetRootComponent()->SetVisibility(true);
	}
	if (PlayEndSound) {
		USoundWave* SoundCue = LoadObject<USoundWave>(nullptr, TEXT("SoundWave'/Game/StarterContent/Audio/tada.tada'"));
		if (!(SoundCue == nullptr))
		{
			UGameplayStatics::PlaySound2D(OtherActor, SoundCue);
		}
	}
}


