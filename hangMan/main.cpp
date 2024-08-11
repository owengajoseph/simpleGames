#include <iostream>
#include "header/random.h"

namespace WordList
{
    enum Word : int
    {
        broccoli,
        account,
        almost,
        spaghetti,
        opinion,
        beautiful,
        distance,
        luggage,
        maxwords

    };

}
std::string_view getString(WordList::Word w)
{
    switch (w)
    {
    case WordList::broccoli:
        return "broccoli";
        break;
    case WordList::account:
        return "account";
        break;
    case WordList::almost:
        return "almost";
        break;
    case WordList::spaghetti:
        return "spahgetti";
        break;
    case WordList::opinion:
        return "opinion";
        break;
    case WordList::beautiful:
        return "beautiful";
        break;
    case WordList::distance:
        return "distance";
        break;
    case WordList::luggage:
        return "luggage";
        break;

    default:
        return "?????";
        break;
    }
}

int main()
{
    std::cout << "Welcome to c++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word" << '\t' << "To  lose : run out of pluses \n";
    WordList::Word w{static_cast<int>(Random::get(0, WordList::maxwords))};
    std::cout << getString(w);
}
