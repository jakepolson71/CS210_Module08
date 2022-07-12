/*
Module 7
Project 3
Assignment 7-1
Jason Polson
SNHU
June, 2022

Chada Tech Grocery Tracking Program for Corner Grocer

Polson_Jason_CS210_ProjectThree.h

*/

#ifndef POLSON_JASON_CS210_PROJECTTHREE_H_
#define POLSON_JASON_CS210_PROJECTTHREE_H_

#include <string>
#include <iostream>


using namespace std;


void CallProcedure(string pName);		// function to call a specific Python procedure
int callIntFunc(string proc, int param);


void GetItemFrequency(string param);	// function to get the procedure for the frequency of a specific item
void MakeHistogram();
void MainMenuStart();		// function to control the main menu
void DisplayMenu();		// function to display the main menu
void SelectionOne();	// function to control the first menu selection
void SelectionTwo();	// function to control the second menu selection
void SelectionThree();	// function to control the third menu selection
void SelectionFour();	// function to control the fourth menu selection


#endif