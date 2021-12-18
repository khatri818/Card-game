#include <iostream>
#include <ctime>

using namespace std;

class Player {
  public:
    string name;
    float balance;
    float starting_balance;

  public:
    Player() {
      name = "";
      balance = 0;
      starting_balance = 0;
    }
};

class Card {
  private:
    int rank;
    int suit;

  public:
    Card() {
      srand(time(NULL));
      rank = (1 + (std::rand() % (int)(13)));
      suit = (1 + (std::rand() % (int)(4)));
    }

    int get_rank() {
      return rank;
    }

    string get_rank_string() {
      if (rank == 1) return "Ace";
      if (rank == 2) return "Two";
      if (rank == 3) return "Three";
      if (rank == 4) return "Four";
      if (rank == 5) return "Five";
      if (rank == 6) return "Six";
      if (rank == 7) return "Seven";
      if (rank == 8) return "Eight";
      if (rank == 9) return "Nine";
      if (rank == 10) return "Ten";
      if (rank == 11) return "Jack";
      if (rank == 12) return "Queen";
      if (rank == 13) return "King";
      else return "Uknown rank";
    }

    int get_suit() {
      return suit;
    }

    string get_suit_string() {
      if (suit == 1) return "Diamonds";
      if (suit == 2) return "Hearts";
      if (suit == 3) return "Spades";
      if (suit == 4) return "Clubs";
      else return "Unknown suit";
    }
};
int main() {
  int dealer_rank;
  int player_rank;
  float bet;
  int choice;
  Card card;
  Player player = Player();

  cout << "Enter your first name only: "<<endl;
  cin >> player.name;

  control:
  player.starting_balance=2000;

  player.balance = player.starting_balance;

  while (player.balance > 0 && (player.balance < player.starting_balance * 5)) {
    cout << player.name << ", you have Rs."
         << player.balance;

    while (bet == 0 || bet > player.balance) {
      cout << "\nHow much money do you want to bet? ";
      cin >> bet;

      if (bet > player.balance) {
        cout << "\nyou don't have enough money to make that bet, Try again later.\n";
      }
    }

    card = Card();
    dealer_rank = card.get_rank();

    cout << "You draw a " << card.get_rank_string()
         << " of " << card.get_suit_string() << ".\n";
    cout << "The next card be higher or lower? "
         << "choose:\n1-higher \n2-lower \n";
    cin >> choice;

    card = Card();
    player_rank = card.get_rank();

    cout << "\n\nYou draw a " << card.get_rank_string()
         << " of " << card.get_suit_string() << ".\n";

    if ((choice == 1 && dealer_rank > player_rank) ||
        (choice == 2 && dealer_rank < player_rank)) {
      player.balance -= bet;

      cout<< "\n\n!!!!!!!!!!!!!!!!!!!!!!Loose!!!!!!!!!!!!!!!!!!!!!!!!\nYou lose Rs." << bet << ".\n\n";
    } else {
      player.balance += bet;

      cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!!Win!!!!!!!!!!!!!!!!!!!!!!!\nYou won Rs." << bet << "!\n\n";
    }

    bet = 0;
  }

  if (player.balance <= 0) {
    cout << "Too bad " + player.name << ". "
         << "You are out of money!\n"
         <<"Want to try again? Enter Y/N \n";
         char flag;
         cin>>flag;
         if(flag=='Y'||flag=='y')
         {
                goto control;
         }
         else
         {
             exit(0);
         }
  }
  else {
    cout << "\n\n!!!!!!!!!!!!!Congratulation!!!!!!!!!!!!!\n\nYou won the game " + player.name << "!";
  }

  return 0;
}
