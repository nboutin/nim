
//#include "menu_view.h"
//#include "minmax.h"
//#include "nim.h"
//#include "view_ascii.h"
//
//#include <iostream>
//#include <string>
//
// using namespace nim;
// using namespace std;
// using namespace ai;

#include <ncurses.h>

int main()
{
    int ch;

    initscr();            /* Start curses mode 		*/
    raw();                /* Line buffering disabled	*/
    keypad(stdscr, TRUE); /* We get F1, F2 etc..		*/
    noecho();             /* Don't echo() while we do getch */

    printw("Type any character to see it in bold\n");
    ch = getch();                 /* If raw() hadn't been called
                                   * we have to press enter before it
                                   * gets to the program 		*/
    if(ch == KEY_F(1))            /* Without keypad enabled this will */
        printw("F1 Key pressed"); /*  not get to us either	*/
    /* Without noecho() some ugly escape
     * charachters might have been printed
     * on screen			*/
    else
    {
        printw("The pressed key is ");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    }
    refresh(); /* Print it on to the real screen */
    getch();   /* Wait for user input */
    endwin();  /* End curses mode		  */
}

// int main()
//{
//    Menu_View menu;
//    menu.display();
//    auto players = menu.get_players();
//
//    Nim game(menu.get_token_count());
//    game.set_player(player_e::p1, players.at(0));
//    game.set_player(player_e::p2, players.at(1));
//
//    Minmax p1_minmax(game.get_player(player_e::p1), menu.get_ai_level());
//    Minmax p2_minmax(game.get_player(player_e::p2), menu.get_ai_level());
//
//    View_ASCII view(game.get_board());
//
//    while(game.is_finished() == false)
//    {
//        // Display
//        view.set_current_player(game.get_current_player());
//        view.set_history(game.get_history());
//        view.display();
//
//        // Input
//        Board::move_t m;
//        if(game.get_current_player().is_ai())
//        {
//            if(game.get_current_player() == game.get_player(player_e::p1))
//                m = p1_minmax.compute(game, Minmax::algo::minmax_parallel);
//            else if(game.get_current_player() == game.get_player(player_e::p2))
//                m = p2_minmax.compute(game, Minmax::algo::minmax_parallel);
//            else
//                std::abort();
//        }
//        else
//        {
//            std::string input;
//            getline(std::cin, input);
//            if(input.empty())
//            {
//                view.message("Input is invalid");
//                continue;
//            }
//            m = std::stoi(input);
//        }
//
//        // Compute
//        if(game.play(m) == false)
//        {
//            view.message("Input is invalid");
//            continue;
//        }
//    }
//    view.message("Game is finished");
//    view.message("Winner is " + game.get_winner_player()->get_name());
//    view.set_history(game.get_history());
//    view.display();
//}
