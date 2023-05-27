// Fill out your copyright notice in the Description page of Project Settings.


#include "FastEnemy.h"

void AFastEnemy::BeginPlay()
{
	Super::BeginPlay();

	MovementComponent->MaxSpeed = 250;
	_LifeComponent->MaxLife = 2;
	NormalDamage = 1;
	DpsDamage = 1;
}