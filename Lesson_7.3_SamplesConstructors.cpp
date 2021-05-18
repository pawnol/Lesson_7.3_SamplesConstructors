/*
Lesson 7.3 Samples Constructros
Pawelski
5/18/2021
Here are the samples. Focus on both the declaration
of constructors within the class and the creation of
objects from those constructors.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Represents a cat.
*/
class Cat
{
public:
    string name;
    int age;
    double weight;
    string color;

    /*
    Here is a constructor! This overrides the no-parameter
    or default constructor. We typically do this in order
    to specify the default values for the instance variables.
    */
    Cat()
    {
        name = "";
        age = 0;
        weight = 0.0;
        color = "";
    }

    /*
    Here is another constructor. This constructor uses four
    parameters to initialize the instance variables. This is another
    way to get around the issue of duplicate names.
    */
    Cat(string initName, int initAge, double initWeight, string initColor)
    {
        name = initName;
        age = initAge;
        weight = initWeight;
        color = initColor;
    }
};

/*
Represents a dog.
*/
class Dog
{
public:
    string name;
    int age;
    double weight;
    string breed;

    Dog()
    {
        name = "";
        age = 0;
        weight = 0.0;
        breed = "";
    }

    /*
    This constructor demonstrates how to use the this pointer
    to reference the instance variables. This is helpful as
    it allows us to reuse names!
    */
    Dog(string name, int age, double weight, string breed)
    {
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->breed = breed;
    }
};

/*
Represents a single card.
*/
class Card
{
public:
    /*
    Face value of the card.
    0 = spades
    1 = clubs
    2 = diamonds
    3 = hearts
    */
    int face;
    /*
    Rank  of the card.
    11 = Jack
    12 = Queen
    13 = King
    */
    int rank;

    Card(int face, int rank)
    {
        this->face = face;
        this->rank = rank;
    }
};

/*
Represents a hand of cards. The hand can grow and
shrink accourding to the number of cards in the hand.
*/
class Hand
{
public:
    vector<Card> cards;

    /*
    This demonstrate a common constructor that populates
    a vector. Before this code will work, you must seed
    the random number generator in the client code!
    */
    Hand(int numberOfCards)
    {
        for (int i = 0; i < numberOfCards; i++)
        {
            int faceNum, rankNum;
            faceNum = int(rand() % 4);
            rankNum = int(rand() % 13) + 1;
            Card card(faceNum, rankNum);
            cards.push_back(card);
        }
    }

    /*
    This is a function! We will discuss this in the next lesson.
    */
    void printCards()
    {
        for (int i = 0; i < cards.size(); i++)
        {
            string face;
            switch (cards[i].face)
            {
            case 0:
                face = "spades";
                break;
            case 1:
                face = "clubs";
                break;
            case 2:
                face = "diamonds";
                break;
            case 3:
                face = "hearts";
                break;
            }

            string rank;
            switch (cards[i].rank)
            {
            case 1:
                rank = "Ace";
                break;
            case 11:
                rank = "Jack";
                break;
            case 12:
                rank = "Queen";
                break;
            case 13:
                rank = "King";
                break;
            default:
                rank = to_string(cards[i].rank);
                break;
            }
            cout << face << " : " << rank << "\n";
        }
    }
};

int main()
{
    /*
    Example #1
    This shows how to call the different constructors.
    */
    Cat c1();                           // this calls the default constructor
    Cat c2("Smokey", 12, 13.5, "grey"); // this calls the 4-param constructor
    Dog d1();
    Dog d2("Turbo", 3, 70.4, "Chocolate-Lab, Husky");

    /*
    Example #2
    In this example, we use two objects to create card hands.
    Notice how the object itself populates the hand instead of
    the client code.
    */
    srand(time(0));
    Hand player1(7);
    Hand player2(7);
    player1.printCards();
    cout << "\n";
    player2.printCards();
    cout << "\n";
    return 0;
}
