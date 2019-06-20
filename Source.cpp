#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
	ofstream outfile;
	outfile.open("Copy_Paste.txt");


	//Declare strings and initialize
	string SN, PO, Item, Tag, Requester, Summary, Description, Date;
	SN = PO = Item = Tag = Requester = Summary = Description = Date = "";

	
	//Get input
	cout << "Enter the last 4 digits of the PO: ";
		cin >> PO;
		cin.ignore();
	cout << "Enter item that is being installed: ";
		getline(cin, Item);
	cout << "Enter the serial number: ";
		cin >> SN;
	cout << "Enter the tag number: ";
		cin >> Tag;
		cin.ignore();
	cout << "Enter who the item is for: ";
	//cin >> Requester;
	getline(cin, Requester);
		
	outfile << "\nSummary:\n";
	Summary = "Install " + Item + " (SN: " + SN + " Tag: " + Tag + ") for " + Requester;
	outfile << Summary << endl;

	outfile << "\nDescription:\n";
	Description = "Install " + Item + " for " + Requester + "\nSN: " + SN + "\nTag: " + Tag + "\nP000" + PO;
	outfile << Description << endl;
	
	outfile << "\nOriginal WO (Pink and Red):\n";
	outfile << "5. Verify accurate receipt and tag items\n\t1. Date: ";
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	outfile << (now->tm_mon + 1) << "/" << now->tm_mday << "/" << (now->tm_year + 1900) << endl;
	outfile << "\t2. Tag number(s): " << Tag << endl;
	outfile<<"6. Deliver Hardware/Software\n\t1. Created install/delivery case: \n\t2. PO/Requisition number: P000" << PO << endl;
	outfile << "7. Scan PO/Case packet, attach to case, close case, and input into database (Spreadsheet [Fiscal Year])\n\t1. Date completed: \n";

	outfile.close();

	system("pause");
}