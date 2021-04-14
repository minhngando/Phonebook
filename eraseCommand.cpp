/*
	This is a subclass of bookCommand.
	This eraseCommand class will remove a specified phoneBookEntry from the phoneBook if it exists.

*/

#include "phoneBookEntry.h"
#include "phoneBook.h"

#include "command.h"
#include "bookCommand.h"
#include "eraseCommand.h"

#include <iostream>
#include <string>

//constructor
eraseCommand::eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream) : bookCommand(inStream, outStream), book(bookIn)
{
}

//overriding the execute command from command.h
//uses the bookCommand member functions to prompt for name to erase
//prompt messages will be "Enter name to erase"
//after last prompt and user input, outputs either "Phone book entry NAME was erased" or "Phone book entry NAME was not erased"
//delegates the actual erase to the phoneBook class
void eraseCommand::execute() {

	//string variable called name to store user input after prompt
	std::string name;

	//prompts the user, and stores the user input into name
	name = outo2("Enter name to erase");

	//if the entry was successfully erased then output a message saying it was erased
	//if the entry wasn't found/erased, then output a message saying it wasn't erased
	if (book.erase(name)) {
		outo("Phone book entry " + name + " was erased");
	}
	else {
		outo("Phone book entry " + name + " was not erased");
	}

}