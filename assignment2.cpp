#include <string>
#include <iostream>

#include "menuList.h"
#include "command.h"
#include "bookCommand.h"
#include "addUpdateCommand.h"
#include "eraseCommand.h"
#include "printCommand.h"

#include "phoneBook.h"
#include "phoneBookEntry.h"


using namespace std;

int main() {

	//build the phoneBook 
	phoneBook yellowPages = phoneBook();

	//build menuList
	menuList menu("Phone book menu:");
	
	//creating commands
	addUpdateCommand auc = addUpdateCommand(yellowPages, cin, cout);
	printCommand pc = printCommand(yellowPages, cin, cout);
	eraseCommand ec = eraseCommand(yellowPages, cin, cout);

	//build menuItem objects
	menuItem addUpdate('a', "add/update", auc);
	menuItem erase('e', "erase", ec);
	menuItem print('p', "print", pc);

	//add menuItem values to menuList
	menu.add(addUpdate);
	menu.add(erase);
	menu.add(print);

	cout << "Starting the Phone Book" << endl << endl;

	//run the menu
	menu.start();

	system("pause");
	return 0;
}