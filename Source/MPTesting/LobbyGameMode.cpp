// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"
void ALobbyGameMode::PostLogin(APlayerController* newPlayer)
{	
	Super::PostLogin(newPlayer);
	if (GameState) {
		int32 curAmountPlayer = GameState.Get()->PlayerArray.Num();
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(
			1,
				15.f,
				FColor::Blue,
				FString::Printf(TEXT("Player Added! Current Player Nums: %d"),curAmountPlayer)
			);

			APlayerState* newPlayerState = newPlayer->GetPlayerState<APlayerState>();

			if (newPlayerState) {
				FString playerName = newPlayerState->GetPlayerName();
				GEngine->AddOnScreenDebugMessage(
					-1,
					15.f,
					FColor::Cyan,
					FString::Printf(TEXT("New Player Name: %s"), *playerName)
				);
			}

		}
	}
	
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	if (GameState) {
		int32 curAmountPlayer = GameState.Get()->PlayerArray.Num();
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(
				1,
				15.f,
				FColor::Red,
				FString::Printf(TEXT("Player Leave! Current Player Nums: %d"), curAmountPlayer-1)
			);

			APlayerState* newPlayerState = Exiting->GetPlayerState<APlayerState>();

			if (newPlayerState) {
				FString playerName = newPlayerState->GetPlayerName();
				GEngine->AddOnScreenDebugMessage(
					-1,
					15.f,
					FColor::Cyan,
					FString::Printf(TEXT("Leaved Player Name: %s"), *playerName)
				);
			}

		}
	}
}
