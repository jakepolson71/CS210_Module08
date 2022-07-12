/*
Module 7
Project 3
Assignment 7-1
Jason Polson
SNHU
July, 2022

Chada Tech Grocery Tracking Program for Corner Grocer

Polson_Jason_CS210_ProjectThree.cpp

*/


#include <Python.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <iomanip>

#include "Polson_Jason_CS210_ProjectThree.h"


using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("CS210ProjectThree");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}



/*
Description:
	This just an altered form of the function given in the original C++ sample code
	Instead of taking generic input, it just calls a set Python function and can't
	be used to call any other function.  The original is much better, but it was a
	requirement of the project to write a new function
*/
void GetItemFrequency(string param)
{
	string proc = "ItemFrequency";	// set a constant procedure name

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());

	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"CS210ProjectThree");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}

	// display the results
	cout << "That item was purchased " << _PyLong_AsInt(presult) << " times today." << endl;

	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;
	
}




int main()
{

	// start the main menu function
	MainMenuStart();


	return 0;

}


// Function to control the main menu
void MainMenuStart()
{
	int i = 0;
	int quitButton = 0;		// variable to control quit out of main loop
	char keyPress;
	
	while (quitButton == 0)		// main program loop
	{
		DisplayMenu();

		cin >> keyPress;		// get user selection

		//  call proper choices from user selection
		switch (keyPress)
		{
		case '1':
			SelectionOne();
			break;
		case '2':
			SelectionTwo();
			break;
		case '3':
			SelectionThree();
			break;
		case '4':
			quitButton = 1;
			SelectionFour();
			//quitButton = 1;
			break;
		default:			// if wrong selection, display error message and start over
			cout << "Invalid selection.  Please try again." << endl;
			break;
		}

		// drop some line breaks to keep space between menus			
		cout << endl << endl << endl << endl << endl;
		

		
	}


}


void DisplayMenu() 
{
	int i = 0;

	// use a for loop to create the top line of asterisks
	for(i = 0; i < 66; i++)
	{
		cout << "*";
	}

	// use standard cout lines to create the menu itself
	cout << endl;

	cout << "*                                                                *" << endl;

	cout << "*     " << "1.....Get Number of Times Each Item Appears in One Day" << "     *" << endl;
	cout << "*     " << "2.....Get the Frequency of a Given item               " << "     *" << endl;
	cout << "*     " << "3.....Display Data as a Text-Based Histogram          " << "     *" << endl;
	cout << "*     " << "4.....Quit                                            " << "     *" << endl;
	cout << "*                                                                *" << endl;
	cout << "*     " << "Please select an option...                            " << "     *";
	cout << endl;

	cout << "*                                                                *" << endl;

	// use a for loop to create the bottom line of asterisks
	for (i = 0; i < 66; i++)
	{
		cout << "*";
	}

	cout << endl;

}

// function to control the first menu selection
void SelectionOne() {
	cout << endl << "You selected Option 1.....Get Number of Times Each Item Appears in One Day." << endl << endl;
	CallProcedure("ItemCount");
	
}

// function to control the second menu selection
void SelectionTwo() {
	string reply;

	cout << endl << "You selected Option 2.....Get Number of Times a Specific Item Appears in One Day." << endl << endl;

	// get the user's choice of item
	cout << "Please enter the item you would like to look up: " << endl;
	cin >> reply;

	// call the function that gets the reply from Python
	GetItemFrequency(reply);

}

// function to control the third menu selection
void SelectionThree() {
	cout << endl << "You selected Option 3.....Display Data as a Text-Based Histogram" << endl << endl;

	CallProcedure("GetPythonHistoData"); // call function to call a Python procedure that writes the .dat file

	MakeHistogram();	// call the C++ function to print the text graph
	
}

// function to control the fourth menu selection
void SelectionFour() {
	cout << endl << "You selected Option 4.....Quit" << endl;
	cout << "The application will now quit." << endl;
	cout << "Goodbye..." << endl;

}


void MakeHistogram()
{
	ifstream dataFileFromPython("frequency.dat");
	string itemLine;
	string itemName;
	int itemQty;

	if(!dataFileFromPython)
	{
		cout << "frequency.dat file not found, unable to open..." << endl;
	}

	while (true)
	{
		dataFileFromPython >> itemName;
		if (dataFileFromPython.eof())
		{
			break;
		}

		cout << left << setw(15);
		cout << itemName << "";
		

		dataFileFromPython >> itemQty;

		for(int i = 0; i < itemQty; i++)
		{
			cout << "#";
		}

		cout << endl;

		if(dataFileFromPython.eof())
		{
			dataFileFromPython.close();
		}
	}

	dataFileFromPython.close();

}
