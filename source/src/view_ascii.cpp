
#include "view_ascii.h"

#include <iomanip>
#include <iostream>

using namespace nim;
using namespace std;

View_ASCII::View_ASCII(const Board& b) : board(b), current_player("") {}

void View_ASCII::display(bool clear)
{
    if(clear && std::system("clear") == -1)
        return;

    cout << "Nim v0.3.0\n";

    print_grid(board);
    print_history();
    cout << current_player.get_name() << ":";

    for(const auto& msg : msgs)
        cout << msg << '\n';

    cout << flush;
    msgs.clear();
}

void View_ASCII::message(const std::string& msg) { msgs.push_back(msg); }

void View_ASCII::print_history() const
{
    cout << "History:";
    for(auto h : history)
    {
        if(h)
            cout << (int) h.value();
        else
            cout << '-';
        cout << ",";
    }
    cout << '\n';
}

void View_ASCII::print_grid(const Board& b) const
{
    for(auto i = 1; i < b.get_default_tokens() + 1; ++i)
        cout << setw(3) << std::to_string(i);
    cout << "\n ";

    for(auto i = 0; i < b.get_tokens(); ++i)
        cout << " | ";
    cout << '\n';
}
