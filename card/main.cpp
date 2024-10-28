#include <iostream>
#include <string_view>
#include <array>
#include <vector>
struct Card
{
    enum Rank
    {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_ranks
    };

    enum Suit
    {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };

    Rank rank{};
    Suit suit{};

    friend std::ostream operator<<(std::ostream &out, Card &card)
    {
        std::vector rankInitials{"a", "2", "3", "4", "5", "6", "7", "8", "9", "j", "q", "k"};
        out << rankInitials[card.rank];
        return out;
    }
};

int main()
{
    Card card{Card::rank_jack, Card::suit_club};

    std::cout << card;
}
