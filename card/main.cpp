#include <iostream>
#include <string_view>

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
    // i should return here the first intials this can only return one? how do return the second
    constexpr std::string_view getInitialsRank(Card::Rank rank)
    {
        // this can do both the work if i make the swith long.
        switch (rank)
        {
            case Card::rank_2:
            return "2";
            case Card::rank_3:
            return "3";
            case Card::rank_4:
            return "4";
            case Card::rank_5:
            return "5";
            case Card::rank_6:
            return "6";
            case Card::rank_7:
            return "7";
            case Card::rank_8:
            return "8";
            case Card::rank_9:
            return "9";
            case Card::rank_jack:
            return "j";
            case Card::rank_queen:
            return  "k";
            case Card::rank_ace:
            return "a";
        }
        return "unknown";
      }
    constexpr std::string_view getInitialsSuit(Card::Suit suit)
    {
        switch (suit)
        {
        case Card::suit_club:
            return "H";
        case Card::suit_diamond:
            return "d";
        case Card::suit_heart:
            return "h";
        case Card::suit_spade:
            return "s";
        
        }
        return "uknown";
    }
    // i should pass two swith statements.

    friend std::ostream operator<<(std::ostream &out, Card &card)
    {
        out <<getInitialsRank(card.rank)<<getInitialsSuit(card.suit);
         return out;
    }
};

int main()
{
    Card card{Card::rank_jack, Card::suit_club};

    std::cout << card;
}
