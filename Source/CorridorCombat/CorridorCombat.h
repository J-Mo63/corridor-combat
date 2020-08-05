// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// Custom print macro
#ifndef PRINT
#define PRINT(text, ...) UE_LOG(LogTemp, Error, TEXT(#text), ##__VA_ARGS__)
#endif