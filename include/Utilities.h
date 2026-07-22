#pragma once
#include "Enums.h"
#include <random>


int getValidatedInput(int min, int max);

static std::mt19937 rng(std::random_device{}());

int randomInt(int min, int max);

void printEqualSign();

void printCentered(const std::string& text, int width);

std::string typeToString(Type type);

void screenTitle(std::string text);

void clearScreen();

