// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
using namespace std;
//Input
//number of test cases T
//T test cases
//D - shield
//P - program

int main()
{
	int T = 0;//Test Cases
	int D = 0;//Sheild Damage
	string P = "";//Alien Program


    return 0;
}


int currentDamage(string PPar)
{
	int beam = 1;
	int totalDamage = 0;
	for (int i = 0; i < PPar.length(); i++)
	{

		char current = PPar.at(i);
		if (current == 'C')
		{
			beam = beam * 2;
		}
		else if (current == 'S')
		{
			totalDamage = totalDamage + beam;
		}
	}

	return totalDamage;
}

