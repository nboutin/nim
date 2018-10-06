
#include "nim.h"
//#include "minmax.h"
#include "menu_view.h"
#include "view_ascii.h"

#include <iostream>
#include <string>

using namespace nim;
using namespace std;
// using namespace ai;

int main(int argc, char* argv[])
{
    Menu_View menu;
    menu.display();
    auto players = menu.get_players();

    Nim game;
    game.set_player(player_e::p1, players.at(0));
    game.set_player(player_e::p2, players.at(1));

    View_ASCII view(game.get_board().get_tokens());

    //    Minmax minmax(game.get_player(player_e::p1), menu.get_ai_level());

    while(game.is_finished() == false)
    {
        // Display
        view.set_current_player(game.get_current_player());
        view.set_history(game.get_history());
        view.display();

        // Input
        std::string input;
        getline(std::cin, input);
        if(input.empty())
        {
            view.message("Input is invalid");
            continue;
        }
        //        if(game.get_current_player().is_ai())
        //            y = minmax.compute(game, Minmax::algo::minmax_parallel, chrono::seconds(5));
        //        else
        //        cin >> m;

        // Compute
        if(game.play(std::stoi(input)) == false)
        {
            view.message("Input is invalid");
            continue;
        }
    }
    view.message("Game is finished");
    view.message("Winner is " + game.get_winner_player()->get_name());
    view.set_history(game.get_history());
    view.display();
}
