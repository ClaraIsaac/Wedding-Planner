//Name: Clara Issa Isaac.        Sec.: 3             B.N.:14
//Name: Merna Wagih Mansour.     Sec.: 4             B.N.:21

#include <iostream>
#include <cstring> //for strlen
#include <cmath> //for pow
using namespace std;

class Event
{
private:
	char EventName[50]; //max. number of character 50 with the null character.
	char CustomerName[50];  //max. number of character 50 with the null character.
	char GuestCount1[50]; //The compiler will treat the program as an array of characters so it can check if the user entered a right input.
	int GuestCount;
	char EventDuration1[50]; //The compiler will treat the program as an array of characters so it can check if the user entered a right input.
	int EventDuration;
	int NumberOfWaiters;
	float CostPerWaiter;
	float FoodCost;
	float TotalCost;
	float DepositAmount;
public:
	void getEventName();
	void getCustomerName();
	void getGuestCount();
	void getEventDuration();
	void CalcualteCost();
	void PrintInfo();
};


void Event::getEventName()
{
	cout << "Enter the name of the event \n";
	cin.getline(EventName, 50);
}


void Event::getCustomerName()
{
	cout << "Enter the customer's first and last name \n";
	cin.getline(CustomerName, 50);
}


void Event::getGuestCount()
{
	cout << "Enter the number of guests." << endl;
	cin.getline(GuestCount1, 50);
	//Check if the user entered right input (digits only)
	// m for the length of the input and f for stop asking the user to enter an input once he entered the right one.
	int m;
	bool f = true;
	while (f)
	{
		m = strlen(GuestCount1);
		for (int i = 0; i < m; i++)
		{
			//isdigit to check if the input is digit.
			if (isdigit(GuestCount1[i]) == 0)
				break;
			if (GuestCount1[i] == 48 && i == 0) //if the first number is 0
				break;
			else if (isdigit(GuestCount1[i]) != 0 && i == m - 1) // if the whole list is integers
				f = false;
		}
		if (f) //any wrong inputs thet require the user to reenter a new input
		{
			cout << "you can only Enter positive integer numbers." << endl;
			cin.getline(GuestCount1, 50);
		}
	}
	//If the input is right so we need to convert it to an integer number.
	GuestCount = 0;
	for (int k = 0; k < m; k++)
	{
		// 48 is ASCII value for 0, we used pow that return 10 power k.
		GuestCount += (GuestCount1[m - k - 1] - 48) * pow(10, k);
	}
}


void Event::getEventDuration()
{
	cout << "Enter the number of minutes in the event \n";
	cin.getline(EventDuration1, 50);
	//Check if the user entered right input (digits only or with .)
	// m for the length of the input and f for stop asking the user to enter an input once he entered a right one.
	int m;
	//Point is the index of a point in the input if the user entered a float number.
	int point=0 , c=0; //for floating point and a counter for how many (.) the user entered
	bool f = true;
	while (f)
	{
		m = strlen(EventDuration1);
		for (int i = 0; i < m; i++)
		{
			//if the first input is 0 and doesn't have . after it
			if (EventDuration1[i] == 48 && i == 0){
				if (EventDuration1[i + 1] == 46 && c == 0);
				else { f = true; break; }
			}
			//isdigit to check if the input is digit, 46 is ASCII value for (.)
			else if (isdigit(EventDuration1[i]) == 0 && EventDuration1[i] != 46)
			{
				f = true; break;
			}
			//if it has (.) input
			else if (EventDuration1[i] == 46)
			{
				if (c == 1) { f = true; break; }//To check whether the user has entered two or more dots
				else { point = i; c++; }
			}
			else if (isdigit(EventDuration1[i]) != 0 && i == m - 1)
				f = false;
		}
		if (f || c>1)
		{
			cout << "you can only Enter positive numbers." << endl;
			cin.getline(EventDuration1, 50);
			c = 0;
		}
	}
	//If the input is right so we need to convert it to a float number.
	// 48 is ASCII value for 0, we used pow that return 10 power k.
	double x = 0;
	for (int k = 0; k < m; k++)
	{
		if (c==1)
		{
			if (EventDuration1[k] != 46 && k < point)
				x += (EventDuration1[point - k - 1] - 48) * pow(10, k);
			else if (EventDuration1[k] != 46 && k > point)
				x += (EventDuration1[k] - 48) * pow(10, -(k - point));
		}
		else
			x += (EventDuration1[m - k - 1] - 48) * pow(10, k);
	}
	EventDuration = ceil(x); //to take the approximate time in minuits.
}


void Event::CalcualteCost()
{
	NumberOfWaiters = GuestCount / 20;
	if ((GuestCount % 20)) // for each 20 guest a one waiter is neeeded
		NumberOfWaiters++;

	CostPerWaiter = 0;
	//for less than an hour
	if (EventDuration < 60)
	{
		CostPerWaiter = EventDuration;
	}
	//for an hour or more
	else
	{
		while (EventDuration >= 60)
		{
			CostPerWaiter += 46.5;
			EventDuration -= 60;
		}
		CostPerWaiter += EventDuration;
	}

	FoodCost = 54.5 * GuestCount;

	TotalCost = FoodCost + (CostPerWaiter * NumberOfWaiters);

	DepositAmount = 0.25 * TotalCost;
}

void Event::PrintInfo()
{
	cout << "-------------------------------------- \n";
	cout << EventName << " Event \n";
	cout << "Event estimate for " << CustomerName << endl;
	cout << "-------------------------------------- \n";
	cout << "Number of Waiters: " << NumberOfWaiters << endl;
	cout << "The cost per Waiter: " << CostPerWaiter << endl;
	cout << "The cost for food is: " << FoodCost << endl;
	cout << "Total cost is: " << TotalCost << endl;
	cout << "Please provide a 25% deposit to reserve the event" << endl;
	cout << "The deposit needed is: " << DepositAmount << endl;
}

int main()
{
	Event event1;
	event1.getEventName();
	event1.getCustomerName();
	event1.getGuestCount();
	event1.getEventDuration();
	event1.CalcualteCost();
	cout << endl;
	event1.PrintInfo();
	return 0;
}
