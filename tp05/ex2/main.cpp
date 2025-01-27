#include "Card.hpp"    // Card
#include "Player.hpp"  // Player
#include "Tracker.hpp" // assert_no_copy

#include <cassert>  // assert
#include <iostream> // cout
#include <thread>   // this_thread

int main(int argc, char** argv)
{
    {
        {
            Card c1 { 8, "Pique" };
            std::cout << c1 << std::endl;
            assert_no_copy("8 de Pique");

            const Card c2 { 8, "Pique" };
            std::cout << (c2 == c1) << std::endl; // -> 1
            assert_no_copy("Egalité 1");
            const Card c3 { 10, "Carreau" };
            std::cout << (c2 == c3) << std::endl; // -> 0
            assert_no_copy("Egalité 2");

            std::cout << (c1 < c2) << std::endl; // -> 0
            assert_no_copy("Inégalité 1");
            std::cout << (c1 < c3) << std::endl; // -> 1
            assert_no_copy("Inégalité 2");
            std::cout << (c3 < c1) << std::endl; // -> 0
            assert_no_copy("Inégalité 3");
        }

        std::cout << std::endl << "----- Partie Player -----" << std::endl;

        Player p1 { "Gerald" };
        Player p2 { "Julien" };
        Player::deal_all_cards(p1, p2);
        assert(p1.cards().size() == 16);
        assert(p2.cards().size() == 16);
        assert_mem_count("Fin de deal 1", 32);
        assert_no_copy("Fin de deal 2");

        int max_turn = (argc > 1) ? atoi(argv[1]) : -1;
        std::cout << "Début de la partie" << std::endl;
        if (max_turn > 1)
            std::cout << "Nombre de tours: " << max_turn << std::endl;
        std::cout << "------------------" << std::endl;

        while (Player::play(p1, p2) && Player::turn_number != max_turn)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            assert_no_copy("Dans le while 1, tour n°" + std::to_string(Player::turn_number));
            assert_mem_count("Dans le while 2", 32);
        }

        std::cout << "Fin de partie: ";
        if (p1.cards().size() > p2.cards().size())
            std::cout << p1.name() << " gagne !" << std::endl;
        else if (p1.cards().size() < p2.cards().size())
            std::cout << p2.name() << " gagne !" << std::endl;
        else
            std::cout << "égalité parfaite !!" << std::endl;

        assert_no_copy("Fin de Partie");
    }
    assert_no_copy("Après déallocation totale");
    assert_mem_count("Après déallocation totale", 0);
}
