//necessary libraries
#include <iostream>
#include<string> 
#include <Windows.h>
#include <iomanip>
using namespace std;

//function to change the text colour of our command line
void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//recursive function where we add the initial stop as s=1
void busRoute(int s = 1) {
    //fare is null as we will add payments per passenger throughout the trip
    float fare{ 0 };
    //number of bus stops array have upper-bound of seven
    int stops{ 7 };
    //max amount of people that a bus can contain
    static const int stop = 60;
    //passenger per stop is undefined array as we will add people throughout the trip
    int passenger[stop] = {};

    Color(4);
    //keeps track of the number of stops for seven stops along route
    cout <<endl;
    cout << "Stop Number " << s << " Out Of 7" << endl;
    cout << "-----------------------" << endl;
    //if our initial stop reaches upper-bound 7
    if (s == stops)
    {
        //the journey ends and breaks the loop
        cout << "The Bus has reached the end of its route." << endl;
        //recursion call
        return;
    }

    //while our initial stop has not yet reached upper-bound 7, increase the stop++
    for (int i = 0; i < stop; i++)
    {
        //if we reach the end of the journey, unboard passenger
        if (passenger[i] <= s)
        {
            passenger[i] = 0;
        }
    }
    char boarding;
    int profit;	

    //notify passenger boarding
    Color(11);  
    cout << "All aboard! The bus has stopped for passenger boarding." << endl;

    //board passengers and add fares upon route until stop number seven is reached
    for (int i = 0; i < stop; i++)
    {
        //if there is no passenger, allow for passenger to board
        if (passenger[i] == 0)
        {
            Color(7);
            cout << endl;
            cout << "Is a passenger currently boarding the bus? (y/n) ";
            //outputs boarding passenger as 1
            cin >> boarding;
            //if there is no more passengers boarding, 
            if (boarding != 'y')
            {
                //break out of the loop and continue on route
                break;
            }
            //keep track of the passengers on the bus
            cout << "At what stop will the passenger get off? (2-7)";
            //stores the number of passengers per route
            cin >> passenger[i];
            cout << "Fare charged for passenger (R): ";
            //stores the fare amount
            cin >> profit;
            //adds the amount to the payments
            fare += profit;
        } 
    }
    //notify passenger exit
    Color(3);
    cout << endl;
    cout << "Passengers who have reached the end of their trip are unboarding the bus..." << endl;
    Color(2);
    //notify route init
    cout << "All routed passengers have boarded. Heading to next stop!" << endl;
    Color(10);
    cout << "Total revenue for trip: R " << fare << endl;
    //recursion call
    Color(7);
    busRoute(s + 1);
}
//main CPP function
int main()
{  
//recursive function call
    busRoute();
    return 0;
}
