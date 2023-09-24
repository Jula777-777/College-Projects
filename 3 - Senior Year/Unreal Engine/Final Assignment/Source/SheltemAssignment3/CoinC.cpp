// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinC.h"

#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACoinC::ACoinC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetBoxExtent({ 35.0f, 7.0f, 32.0f });
	CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &ACoinC::OnOverlapBegin);

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CoinStaticMesh(TEXT("/Game/Coins/coin-fbx/GoldCoin.GoldCoin"));

	if (CoinStaticMesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(CoinStaticMesh.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	VisualMesh->SetRelativeScale3D({ 0.21f, 0.21f, 0.21f });
}

// Called when the game starts or when spawned
void ACoinC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoinC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator NewRotation = GetActorRotation();
	float DeltaRotation = DeltaTime * 180.0f;
	NewRotation.Yaw += DeltaRotation;
	SetActorRotation((NewRotation));
}

void ACoinC::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OverlappedComp->CastShadow==1) {
		if (!OtherActor->ActorHasTag("hurts")) {
			if (visible)
			{
				VisualMesh->SetHiddenInGame(true);
				VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

				USoundWave* SoundCue = LoadObject<USoundWave>(nullptr, TEXT("SoundWave'/Game/Coins/Game-coin-collect-620.Game-coin-collect-620'"));
				if (!(SoundCue == nullptr))
				{
					UGameplayStatics::PlaySoundAtLocation(CollisionMesh->GetWorld(), SoundCue, CollisionMesh->GetComponentLocation());
				}
				visible = false;

				if (Door != nullptr)
				{
					Door->open();
				}
			}
		}
	}
}


