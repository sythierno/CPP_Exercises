#include <iostream>
#include <vector>

void ajoute_double(const std::vector<int>& un, std::vector<int>& v) {
    v.reserve(v.size() + un.size());
    for (const auto n : un)
    {
        v.emplace_back(n * 2);
    }
}

void affiche(const std::vector<int>& v) {
    std::cout << "Le tableau contient les valeurs :";
    for (auto entier : v)
    {
        std::cout << " " << entier;
    }
    std::cout << std::endl;
}

int main() {
    auto entiers = std::vector<int> {};
    int  value   = 0;
    while (1)
    {
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cout << "Ceci n'est pas un entier !" << std::endl;
            return 1;
        }
        if (value == 0)
        {
            break;
        }
        if (value < 0)
        {
            if (!entiers.empty())
                entiers.pop_back();
        }
        else
        {
            entiers.emplace_back(value);
        }
    }
    affiche(entiers);
    std::cout << "first: " << entiers[0] << "    last: " << entiers[entiers.size() - 1] << std::endl;
    ajoute_double(entiers, entiers);

    affiche(entiers);
    return 0;
}