// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowEnemy.h"

void ASlowEnemy::BeginPlay()
{
	Super::BeginPlay();

	MovementComponent->MaxSpeed = 20;
	_LifeComponent->MaxLife = 50;
	NormalDamage = 10;
}