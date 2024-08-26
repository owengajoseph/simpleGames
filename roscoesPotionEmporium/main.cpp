#include <array>
#include <iostream>
#include <limits> // for std::numeric_limits
#include <string_view>
#include "random.h"

namespace Potion
{
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_potions
    };

    constexpr std::array types { healing, mana, speed, invisibility }; // An array of our enumerators

    // We could put these in a struct, but since we only have two attributes we'll keep them separate for now
    // We will explicitly define the element type so we don't have to use the sv suffix
    constexpr std::array<std::string_view, max_potions> name { "healing", "mana", "speed", "invisibility" };
    constexpr std::array cost { 20, 30, 12, 50 };

    static_assert(std::size(types) == max_potions);  // ensure 'all' contains the correct number of enumerators
    static_assert(std::size(cost) == max_potions);
    static_assert(std::size(name) == max_potions);
}

class Player
{
private:
    static constexpr int s_minStartingGold { 80 };
    static constexpr int s_maxStartingGold { 120 };

    std::string m_name {};
    int m_gold {};
    std::array<int, Potion::max_potions> m_inventory { };

public:
    explicit Player(std::string_view name) :
        m_name { name },
        m_gold { Random::get(s_minStartingGold, s_maxStartingGold) }
    {
    }

    // returns false if can't afford, true if purchased
    bool buy(Potion::Type type)
    {
        if (m_gold < Potion::cost[type])
            return false;

        m_gold -= Potion::cost[type];
        ++m_inventory[type];
        return true;
    }

    int gold() const { return m_gold; }
    int inventory(Potion::Type p) const { return m_inventory[p]; }
};

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int charNumToInt(char c)
{
    return c - '0';
}

Potion::Type whihcPotion()
{
    std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
    char input{};
    while (true)
    {
        std::cin >> input;
        if (!std::cin)
        {
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // and remove the bad input
            continue;
        }

        // If there is extraneous input, treat as failure case
        if (!std::cin.eof() && std::cin.peek() != '\n')
        {
            std::cout << "I didn't understand what you said.  Try again: ";
            ignoreLine(); // ignore any extraneous input
            continue;
        }

        if (input == 'q')
            return Potion::max_potions;

        // Convert the char to a number and see if it's a valid potion selection
        int val { charNumToInt(input) };
        if (val >= 0 && val < Potion::max_potions)
            return static_cast<Potion::Type>(val);

        // It wasn't a valid potion selection
        std::cout << "I didn't understand what you said.  Try again: ";
        ignoreLine();
    }
}

void shop(Player &player)
{
    while (true)
    {
        std::cout << "Here is our selection for today:\n";

        for (auto p: Potion::types)
            std::cout << p << ") " << Potion::name[p] << " costs " << Potion::cost[p] << '\n';

        Potion::Type which { whichPotion() };
        if (which == Potion::max_potions)
            return;

        bool success { player.buy(which) };
        if (!success)
            std::cout << "You can not afford that.\n\n";
        else
            std::cout << "You purchased a potion of " << Potion::name[which] << ".  You have " << player.gold() << " gold left.\n\n";
    }
}

void printInventory(Player& player)
{
    std::cout << "Your inventory contains: \n";

    for (auto p: Potion::types)
    {
        if (player.inventory(p) > 0)
            std::cout << player.inventory(p) << "x potion of " << Potion::name[p] << '\n';
    }

    std::cout << "You escaped with " << player.gold() << " gold remaining.\n";
}

int main()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";
    std::cout << "Enter your name: ";

    std::string name{};
    std::cin >> name;

    Player player { name };

    std::cout << "Hello, " << name << ", you have " << player.gold() << " gold.\n\n";

    shop(player);

    std::cout << '\n';

    printInventory(player);

    std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";

    return 0;
}
