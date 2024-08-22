#include <iostream>
#include <string_view>
#include <array>
#include "random.h"
// class should store name ,
class Player
{
private:
    std::string m_name{"???"};
    int randNum{};

public:
    Player(const std::string &playName, int randNum)
        : m_name{playName}, randNum{randNum}
    {
    }
    // enum containing type of portion compud
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_potions
    };
    // print the name of the object constructed.
    void printNameandGold()
    {
        std::cout << "Hello," << m_name << ", you have " << randNum << " Gold\n";
    }
};
void shop()
{
    std::cout << "here is our selection for today \n";
    constexpr std::array types{Player::healing, Player ::mana, Player::speed, Player::invisibility};
    constexpr std::array<std::string_view, Player::max_potions> name{"healing", "mana", "speed", "invisibility"};
    std::array cost{20, 30, 12, 50};

    for (std::size_t i{0}; i < std::size(types); ++i)
    {
        std::cout << i << ")" << name[i] << " costs " << cost[i] << '\n';
    }
}

// print the name of the object constructed.

// enum containing the types of potion.

int main()
{
    std::cout << "welcome to roscoes's potion emporium!\n";
    std::string name{};
    std::cout << "enter your name \n";
    std::cin >> name;
    Player playerName{name, Random::get(1, 100)};
    playerName.printNameandGold();
    shop();
}
