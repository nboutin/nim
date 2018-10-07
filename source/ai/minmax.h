
#pragma once

#include "nim.h"

#include <chrono>
#include <array>

namespace ai
{
class Minmax
{
public:
    static constexpr auto DURATION_MIN = std::chrono::seconds(0);
    enum class algo { minmax };

    using depth_t = int16_t;

    Minmax(const nim::Player& p, depth_t depth);

    nim::Board::move_t
    compute(nim::Nim game, algo algo, std::chrono::seconds duration_min = DURATION_MIN) const;

private:
    std::array<nim::Board::move_t, nim::Board::MOVE_MAX> generate_moves() const;
    bool is_leaf(const nim::Nim& game, depth_t depth) const;

    int16_t minmax(nim::Nim& game, depth_t depth, bool is_max) const;

    depth_t depth;
    mutable std::chrono::time_point<std::chrono::high_resolution_clock> start;
    mutable std::chrono::seconds duration_min;
    const nim::Player& player;
};
}
