#pragma once
#include <string>
#include "Enums.h"
#include <random>


int getValidatedInput(int min, int max);

static std::mt19937 rng(std::random_device{}());

int randomInt(int min, int max);

void printEqualSign(int width);

void printCentered(const std::string& text, int width);

std::string typeToString(Type type);

std::string statusToString(Status status);

void screenTitle(std::string text);

void clearScreen();

void animatedText(const std::string& text, int delay = 25);
