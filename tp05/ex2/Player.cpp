#include "Player.hpp"

#include <algorithm> // shuffle
#include <iostream>  // cout, endl
#include <random>    // default_random_engine, random_device
#include <string>
#include <thread> // this_thread

Player::Player(const std::string& nom)
    : _name(nom)
{}

void Player::deal_all_cards(Player& p1, Player& p2)
{
    // initialiser toutes les cartes
    std::vector<Card> all_cards;
    all_cards.reserve(32);
    for (int valeur = 7; valeur <= 14; ++valeur)
        for (const auto& couleur : { "Coeur", "Pique", "Trèfle", "Carreau" })
            all_cards.emplace_back(valeur, couleur);

    assert_mem_count("Après création deck", 32);

    // mélanger le paquet
    std::random_device rd;
    std::shuffle(all_cards.begin(), all_cards.end(), std::default_random_engine(rd()));

    p1._cards.reserve(32);
    p2._cards.reserve(32);

    for (int i = 0, s = all_cards.size(); i < s; i += 2)
    {
        p1.push_front(std::move(all_cards[i]));
        p2.push_front(std::move(all_cards[i + 1]));
    }
    assert_mem_count("Après distribution", 64);
}

void Player::push_front(Card card)
{
    _cards.insert(_cards.begin(), std::move(card));
}

Card Player::pop_back()
{
    Card res = std::move(_cards.back());
    _cards.pop_back();
    return res;
}

bool Player::play(Player& p1, Player& p2, std::vector<Card> stake)
{
    static std::random_device rd;

    if (p1._cards.empty() || p2._cards.empty())
    {
        if (!stake.empty())
            std::cout << "Egalité, mais pas assez de cartes pour terminer !!" << std::endl;
        return false;
    }

    if (stake.empty())
    {
        stake.reserve(32);
        std::cout << "Tour n°" << ++Player::turn_number << std::endl;
    }

    else
        std::cout << "\tEgalité !!" << std::endl;

    Card p1_card = p1.pop_back();
    Card p2_card = p2.pop_back();
    std::cout << "\t" << p1._name << " joue " << p1_card << " \t" << p2._name << " joue " << p2_card
              << std::endl;

    auto p1_gagne = p2_card < p1_card;
    auto p2_gagne = p1_card < p2_card;

    stake.push_back(std::move(p1_card));
    stake.push_back(std::move(p2_card));

    if (p1_gagne)
    {
        std::shuffle(stake.begin(), stake.end(), std::default_random_engine(rd()));
        auto i = 0;
        for (auto& c : stake)
        {

            assert_mem_count("Play", 34 + i);
            p2.push_front(std::move(c));
            i++;
        }

        std::cout << "\t" << p2._name << " remporte le pli (" << stake.size() << " cartes)" << std::endl;
    }
    else if (p2_gagne)
    {
        std::shuffle(stake.begin(), stake.end(), std::default_random_engine(rd()));
        for (auto& c : stake)
        {
            p1.push_front(std::move(c));
        }

        std::cout << "\t" << p1._name << " remporte le pli (" << stake.size() << " cartes)" << std::endl;
    }
    else
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        return play(p1, p2, std::move(stake));
    }
    return true;
}