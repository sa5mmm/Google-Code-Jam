// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<vector>
using namespace std;
//Input
//number of test cases T
//T test cases
//D - shield
//P - program
int currentDamage(string PPar);
void programInfo(string PPar, vector <int>&infoPar);
int moveShotsTruncateCharges(string &PPar);
int main()
{
	int T = 0;//Test Cases
	int D = 6;//Sheild Damage
	int moves = 0;
	string P = "SCCSSC";//Alien Program
	cout << currentDamage(P);
	vector <int>info;
	if (currentDamage(P) < D)//If damage dealt is less than our sheidl damage we can stop
	{
		moves = 0;
	}
	else//Otherwise we need to try to change it
	{
		programInfo(P, info);
		cout << info[0] << " " << info[1] << " " << info[2] << endl;
		if (info[2] > D)//If the minimum damage is greater than our shield capacity we can never fix this
		{
			//change status to impossible!
		}
		else//We should be able to change the program.
		{
			//We should move Shots near the end towards the beginning to lessen the most damage.
			//We should truncate C's at the end because they have no effect unless a shot comes afterwards.
			cout << moveShotsTruncateCharges(P) << " " << P << endl;
		}

	}




	system("pause");
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



void programInfo(string PPar,vector <int>&infoPar)
{
	int beam = 1;
	int totalDamage = 0;
	int totalCharges = 0;
	int totalShots = 0;
	for (int i = 0; i < PPar.length(); i++)
	{

		char current = PPar.at(i);
		if (current == 'C')
		{
			totalCharges = totalCharges + 1;
			beam = beam * 2;
		}
		else if (current == 'S')
		{
			totalShots = totalShots + 1;
			totalDamage = totalDamage + beam;
		}
	}

	infoPar.push_back(totalDamage);//This is current damage based on order right now.
	infoPar.push_back(totalCharges);//2 to the power of this number times total shots is max damage done by the program
	infoPar.push_back(totalShots);//This is the minimum damage done by the program

}


int moveShotsTruncateCharges(string &PPar)
{
	char prev = ' ';
	int moves = 0;
	for (int i = PPar.length()-1; i >= 0; i--)//This needs to repeat at most the number of shots we have in the Program to move them all to the correct location.
	{
		char current = PPar.at(i);
		if (prev == 'S'&&current == 'C')
		{
			PPar.at(i + 1) = 'C';
			PPar.at(i) = 'S';
			moves = moves + 1;
		}
		prev = PPar.at(i);

	}
	return moves;
}

