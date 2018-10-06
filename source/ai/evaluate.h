
#pragma once

#include "nim.h"

namespace ai
{
constexpr auto WIN_POINT   = 100;
constexpr auto LOOSE_POINT = -WIN_POINT;

int16_t evaluate(const nim::Nim& g, const nim::Player& ai_player);
}
