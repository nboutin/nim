
#include "game_p4.h"

using namespace p4;
using namespace std;

Game_P4::Game_P4()
    : p1("Player 1", Token::color_e::red)
    , p2("Player 2", Token::color_e::yellow)
    , current_player(p1)
{}

bool Game_P4::play(uint8_t x, std::unique_ptr<Token> token)
{
    if(finished)
        return false;

    if(!board.play(x, move(token)))
        return false;

    if(!compute_ending())
        compute_next_player();

    return true;
}

/// \brief Decide if a game is finished
/// \return true if finished otherwise false
///
/// A game is finished, if someone win, if no more token can be added to the board (draw)
bool Game_P4::compute_ending()
{
    const auto& b        = board.get_board();
    auto space_available = false;

    // Look for free cell in the highest row
    for(int x = 0; x < Board::N_COLUMN; ++x)
    {
        space_available |= b[x][0].is_empty();
    }

    auto is_winner = is_winner_vertically(b) || is_winner_horizontally(b) || is_winner_diagonal(b);

    finished = !space_available || is_winner;
    return finished;
}

void Game_P4::compute_next_player()
{
    if(current_player == p1)
        current_player = p2;
    else
        current_player = p1;
}

bool Game_P4::is_winner_vertically(const Board::board_t& b) const
{
    for(int x = 0; x < Board::N_COLUMN; ++x)
    {
        int red    = 0;
        int yellow = 0;
        for(int y = 0; y < Board::N_ROW; ++y)
        {
            const auto& cell = b[x][y];
            if(cell.is_empty())
            {
                red    = 0;
                yellow = 0;
                continue;
            }

            if(cell.get_token().get_color() == Token::color_e::red)
            {
                red++;
                yellow = 0;
            }
            else
            {
                yellow++;
                red = 0;
            }

            if(red >= 4 || yellow >= 4)
                return true;
        }
    }
    return false;
}

bool Game_P4::is_winner_horizontally(const Board::board_t& b) const
{
    for(int y = 0; y < Board::N_ROW; ++y)
    {
        int red    = 0;
        int yellow = 0;
        for(int x = 0; x < Board::N_COLUMN; ++x)
        {
            const auto& cell = b[x][y];
            if(cell.is_empty())
            {
                red    = 0;
                yellow = 0;
                continue;
            }

            if(cell.get_token().get_color() == Token::color_e::red)
            {
                red++;
                yellow = 0;
            }
            else
            {
                yellow++;
                red = 0;
            }

            if(red >= 4 || yellow >= 4)
                return true;
        }
    }
    return false;
}

bool Game_P4::is_winner_diagonal(const Board::board_t& b) const
{
    // Diag '\'
    for(int y = 0; y <= 2; ++y)
    {
        for(int x = 0; x <= 3; ++x)
        {
            int red    = 0;
            int yellow = 0;
            for(int i = 0; i < 4; ++i)
            {
                const auto& cell = b[x + i][y + i];

                if(cell.is_empty())
                {
                    red    = 0;
                    yellow = 0;
                    continue;
                }

                if(cell.get_token().get_color() == Token::color_e::red)
                {
                    red++;
                    yellow = 0;
                }
                else
                {
                    yellow++;
                    red = 0;
                }

                if(red >= 4 || yellow >= 4)
                    return true;
            }
        }
    }

    // Diag '/'
    for(int y = 0; y <= 2; ++y)
    {
        for(int x = 3; x < Board::N_ROW; ++x)
        {
            int red    = 0;
            int yellow = 0;
            for(int i = 0; i < 4; ++i)
            {
                const auto& cell = b[x - i][y + i];

                if(cell.is_empty())
                {
                    red    = 0;
                    yellow = 0;
                    continue;
                }

                if(cell.get_token().get_color() == Token::color_e::red)
                {
                    red++;
                    yellow = 0;
                }
                else
                {
                    yellow++;
                    red = 0;
                }

                if(red >= 4 || yellow >= 4)
                    return true;
            }
        }
    }
    return false;
}
