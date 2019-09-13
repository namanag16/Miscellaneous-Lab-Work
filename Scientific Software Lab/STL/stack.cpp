#include <iostream>
#include <stack>

using namespace std;

int main ()
{
    stack <string> cards; /* Simple enough to create a stack */
    cards.push("King of Hearts"); /* push() will add a value, think of queues */
    cards.push("King of Clubs");  /* adding some cards to the deck */
    cards.push("King of Diamonds");
    cards.push("King of Spades");
    cout << "There are " << cards.size () << " cards in the deck" << endl;
    cout << "The card on the top of the deck is " << cards.top() << endl;
    /* Will output King of Spades, since this was the last one to be added */
    cards.pop();
    cout << "The top card is now " << cards.top() << endl;
    cout << cards.size();

    cin.get ();
    return EXIT_SUCCESS;
}
