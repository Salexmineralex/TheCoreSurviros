// Fill out your copyright notice in the Description page of Project Settings.


#include "NormalEnemy.h"

ANormalEnemy::ANormalEnemy()
{

}

void ANormalEnemy::BeginPlay()
{
	Super::BeginPlay();

	MovementComponent->MaxSpeed = 100;
	_LifeComponent->MaxLife = 10;
	NormalDamage = 5;
}

