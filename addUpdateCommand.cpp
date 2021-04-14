/*
	This is a subclass of bookCommand.
	This addUpdateCommand class will add a new entry if the passed in name is not already in the phoneBook. Otherwise it will update an existing phoneBookEntry

*/

#include "phoneBookEntry.h"
#include "phoneBook.h"

#include "command.h"
#include "bookCommand.h"
#include "addUpdateCommand.h"

#include <iostream>
#include <string>


//constructor
addUpdateCommand::addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream) : bookCommand(inStream, outStream), book(bookIn)
{
}

//overriding the execute command from command.h
//uses the bookCommand member function outo2 to prompt for name, phone number, and email then store the user input into variables
//prompt messages will be "Enter name to add/update", "Enter phone number", "Enter e-mail address"
//after last prompt and input --> "Adding phone book entry for NAME" or "Updating phone book entry for NAME" --> this uses outo not outo2 because don't need to store any inputs, just prompts
//delegates the actual add/update to the phoneBook class
void addUpdateCommand::execute() {

	std::string name, phoneNumber, email;

	//prompts the user, then stores the user input into string variables name, phoneNumber, and email
	name = outo2("Enter name to add/update");
	phoneNumber = outo2("Enter phone number");
	email = outo2("Enter e-mail address");
	
	//using the information from the user input to add or update an entry in the phoneBook
	if (book.find(name)) {
		outo("Updating phone book entry for " + name);
		book.insert(name, phoneNumber, email);
	}
	else {

		outo("Adding phone book entry for " + name);
		book.insert(name, phoneNumber, email);
	}

}
