// Fill out your copyright notice in the Description page of Project Settings.

#include "SpiralAttack.h"

// Sets default values for this component's properties
USpiralAttack::USpiralAttack()
{

	raySphere.Radius = 5.0f,
	raySphere.TraceChannel = ETraceTypeQuery::TraceTypeQuery1,
	raySphere.bTraceComplex = false,
	raySphere.ActorsToIgnore,
	raySphere.DrawDebugType = EDrawDebugTrace::None,
	raySphere.OutHit;
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}

// Called when the game starts
void USpiralAttack::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	
}

// Called every frame
void USpiralAttack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	spiral_timer();
}

FVector USpiralAttack::next_spiral_point(double a, double b, double angle)
{
	const double e = exp(1);
	FVector offset = GetOwner()->GetActorLocation();
	FVector forward = GetOwner()->GetActorForwardVector();
	forward = forward * spiralOffset;

	double r = a * pow(e, b * angle);
	double x = r * cos(angle) + offset.X - (forward.X * 3);
	double y = r * sin(angle) + offset.Y - (forward.Y * 3);
	FVector point = FVector(x, y, GetOwner()->GetActorLocation().Z);

	return (point);
}

void USpiralAttack::do_spiral()
{
	FVector point;
	double scale = 1.2;
	double growth = 0.28;
	FVector pivot;
	int counter = 0;

	for (double angle = 0; angle < 6 * PI; angle += 0.05) {
		point = next_spiral_point(scale, growth, angle);
		pivot = GetOwner()->GetActorLocation();

		if (flip)
			point = rotate_point(pivot, 180, point);
		DrawDebugPoint(GetWorld(), point, 10, FColor::Red, false, 2.0f, 0);
		if (counter % 4 == 0) {
			if (throw_raycast(point)) {
				if (raySphere.OutHit.GetActor());
//					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString().Printf(TEXT("counter = %d"), counter));
					//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, raySphere.OutHit.GetActor()->GetName());
			}
		} else
			GEngine->ClearOnScreenDebugMessages();
		counter++;
	}
}

void USpiralAttack::spiral_timer()
{
	if (spiralTimer < 0) {
		do_spiral();
		spiralTimer = cooldown;
		if (flip)
			flip = false;
		else
			flip = true;
	}
	else
		spiralTimer -= GetWorld()->GetDeltaSeconds();
}

bool  USpiralAttack::throw_raycast(FVector point)
{
	FVector start = point ;
	FVector end = point + (GetOwner()->GetActorForwardVector() * 2);

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString().Printf(TEXT("X = %f"), end.X));
	float sphereRadius = 5.0f;
	const bool bHit = UKismetSystemLibrary::SphereTraceSingle(
		GetWorld(),
		start,
		end,
		raySphere.Radius,
		raySphere.TraceChannel,
		raySphere.bTraceComplex,
		raySphere.ActorsToIgnore,
		raySphere.DrawDebugType,
		raySphere.OutHit,
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		1.5f
	);
	return bHit;
}

FVector rotate_point(FVector pivot, float angle, FVector point)
{
	float s = sin(angle);
	float c = cos(angle);
	FVector p;

	p.X = point.X - pivot.X;
	p.Y = point.Y - pivot.Y;
	p.Z = point.Z;

	float xnew = p.X * c - p.Y * s;
	float ynew = p.X * s + p.Y * c;

	p.X = xnew + pivot.X;
	p.Y = ynew + pivot.Y;

	return p;
}
