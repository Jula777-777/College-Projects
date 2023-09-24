// Fill out your copyright notice in the Description page of Project Settings.


#include "SwingDoor.h"

// Sets default values
ASwingDoor::ASwingDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> DoorStaticMesh(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Door.SM_Door'"));

	if (DoorStaticMesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(DoorStaticMesh.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	VisualMesh->SetRelativeScale3D({ 1.0f, 1.7625f, 1.195f });
}

// Called when the game starts or when spawned
void ASwingDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASwingDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (shouldOpen && numberofTicks < 120)
	{
		FRotator NewRotation = GetActorRotation();
		float DeltaRotation = DeltaTime * 45.0f;
		NewRotation.Yaw += DeltaRotation;
		SetActorRotation((NewRotation));
		numberofTicks++;
	}

}

void ASwingDoor::open()
{
	shouldOpen = true;
}
