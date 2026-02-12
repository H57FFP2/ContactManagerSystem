#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cctype>
#include <string>
#include <array>
#include <tuple>
#include "C_ContactClass.h"
#include "F_ContactManagerFunction.h"
#include "F_Utils.h"

using std::cout;


struct conditionVars {
	const uint16_t maxCharName = 50;
};

int main() {
	Contact contact;
	ContactList contactList;
	Log log;
	conditionVars conVar;
	std::array<std::string, 5> domaines = { "outlook.com", "outlook.fr", "gmail.com", "yahoo-inc.com", "yahoo.com" };

	std::string action;

	while (true) {
		cout << "######################\n";
		cout << "Contact Manager System\n";
		cout << "######################\n\n";

		cout << "Add : Add a contact.\n";
		cout << "Remove : Remove a contact.\n";
		cout << "Show : Show contact list.\n";
		cout << "Quit : Quit program\n\n";

		cout << "Enter action: ";
		std::getline(std::cin, action);

		while (action.empty()) {
			cout << log.getWarn() << "Input empty.\n";
			cout << "Enter action: ";
			std::getline(std::cin, action);
		}

		tolowerc(action);

		if (action.find("add") != std::string::npos) {
			cout << "\n";
			//const Log log, const uint16_t maxCharName, const uint16_t maxCountNum, const uint16_t minCountNum, const std::array<std::string, 5> domaines, Contact& contact, ContactList& contactList
			addContact(conVar.maxCharName, domaines, contact, contactList);
		}
		else if (action.find("remove") != std::string::npos) { removeContact(contactList); }
		else if (action.find("show") != std::string::npos) { showContactList(contactList); }
		else if (action.find("quit") != std::string::npos) { break; }
		else { cout << "Input is not recognized.\n\n"; continue; }

	}
}