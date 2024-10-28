#include <iostream>
#include <string_view>
#include <vector>
#include <cstddef>
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
    // function to return the intials of the cards
    friend std::ostream &operator<<(std::ostream &out, Card &card)
    {
        // how do i return the initials ?
        std::vector getInitials{
            "A",
            "2",
        };
        std::vector getSuit{"C", "D", "H"};

        // return two output streams which i did not know
        out << getInitials[static_cast<std::size_t>(card.rank)] << getSuit[static_cast<std::size_t>(card.suit)];

        return out;
    }
};

int main()
{
    Card card{Card::rank_ace, Card::suit_club};

    std::cout << card;
}
