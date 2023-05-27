// Copyright Epic Games, Inc. All Rights Reserved.

#include "TheCoreSurvivorsCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

//////////////////////////////////////////////////////////////////////////
// ATheCoreSurvivorsCharacter

ATheCoreSurvivorsCharacter::ATheCoreSurvivorsCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rate for input
	TurnRateGamepad = 50.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	this->_LifeComponent = CreateDefaultSubobject<ULifeComponent>(TEXT("_LifeComponent"));

	this->_SpawnActor = CreateDefaultSubobject<USpawnActorsComponent>(TEXT("_SpawnComponent"));
	
	this->_ThowableKnifeSpawner = CreateDefaultSubobject<UThrowableKnifeSpawnerComponent>(TEXT("_ThowableKnifeSpawner"));
	
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	sphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("collision"));
	sphereCollision->SetupAttachment(RootComponent);


}

//////////////////////////////////////////////////////////////////////////
// Input

void ATheCoreSurvivorsCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	//PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &ATheCoreSurvivorsCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &ATheCoreSurvivorsCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	/*PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Turn Right / Left Gamepad", this, &ATheCoreSurvivorsCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Look Up / Down Gamepad", this, &ATheCoreSurvivorsCharacter::LookUpAtRate);*/

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ATheCoreSurvivorsCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ATheCoreSurvivorsCharacter::TouchStopped);
}

void ATheCoreSurvivorsCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	//Jump();
}

void ATheCoreSurvivorsCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	//StopJumping();
}

void ATheCoreSurvivorsCharacter::TurnAtRate(float Rate)
{
	//// calculate delta for this frame from the rate information
	//AddControllerYawInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

void ATheCoreSurvivorsCharacter::LookUpAtRate(float Rate)
{
	//// calculate delta for this frame from the rate information
	//AddControllerPitchInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

void ATheCoreSurvivorsCharacter::MoveForward(float Value)
{

	if ((Controller != nullptr) && (Value != 0.0f))
	{

		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ATheCoreSurvivorsCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}


void ATheCoreSurvivorsCharacter::ReduceAmount_Implementation(float damage)
{

	_LifeComponent->ReduceAmount_Implementation(damage);
}

void ATheCoreSurvivorsCharacter::RestoreAmount_Implementation(float recover)
{
	_LifeComponent->RestoreAmount_Implementation(recover);
}

void ATheCoreSurvivorsCharacter::StartDamageOverTime_Implementation(float dps)
{
	_LifeComponent->StartDamageOverTime_Implementation((dps));
}

void ATheCoreSurvivorsCharacter::StopDamageOverTime_Implementation()
{
	_LifeComponent->StopDamageOverTime_Implementation();
}

void ATheCoreSurvivorsCharacter::BeginPlay()
{
	Super::BeginPlay();

	_LifeComponent->OnKillEntity.BindDynamic(this,&ATheCoreSurvivorsCharacter::KillPlayer);
	sphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ATheCoreSurvivorsCharacter::OnItemOverlap);

}

void ATheCoreSurvivorsCharacter::KillPlayer()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Muerto")));
	
}

void ATheCoreSurvivorsCharacter::OnItemOverlap(UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
	const FHitResult& SweepResult)
{
	AItem* Item = Cast<AItem>(OtherActor);
	
	if (Item)
	{
		AFirstAidKitItem* FirstAidKit = Cast<AFirstAidKitItem>(Item);
		if (FirstAidKit)
		{
			// Incrementa la vida del jugador con el componente LifeComponent
			_LifeComponent->RestoreAmount(FirstAidKit->lifeRecovered);
			FirstAidKit->Destroy();
		}
		else
		{
			AExperienceItem* ExperienceItem = Cast<AExperienceItem>(Item);
			if (ExperienceItem)
			{
				// Incrementa la experiencia del jugador
				//Experience += ExperienceItem->experiencedGained;
			}
		}
	}
}

USphereComponent* ATheCoreSurvivorsCharacter::GetCollisionComponent() const
{
	return sphereCollision;
}
