
#include "menu_view.h"

#include <iostream>

using namespace nim;
using namespace std;

void Menu_View::display()
{
    if(std::system("clear") == -1)
        return;

    for(int p = 1; p <= 2; ++p)
        construct_player(p);
}

void Menu_View::construct_player(int player_num)
{
    cout << "Player " << std::to_string(player_num) << ":\n";

    cout << "Name [Player" << std::to_string(player_num) << "]: ";
    string name;
    getline(cin, name);
    if(name.empty())
        name = "Player" + std::to_string(player_num);

    string player_type;
    do
    {
        cout << "Human or AI [H/a]: ";
        getline(cin, player_type);
    } while(!player_type.empty() && player_type != "H" && player_type != "a");

    if(player_type.empty() || player_type == "H")
        players.push_back(Player{name, false});
    else
        players.push_back(Player{name, true});
}
