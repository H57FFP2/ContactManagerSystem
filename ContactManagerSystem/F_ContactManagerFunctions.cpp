#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <array>
#include <tuple>
#include "F_ContactManagerFunction.h"
#include "C_ContactClass.h"
#include "F_Utils.h"


using std::cout;

struct countryNumberFormat {
	std::string countryFormat;
	uint16_t formatCanada = 1;
	uint16_t formatFrance = 2;
	uint16_t formatUs = 3;
};

// Adding name process to stack.
std::string addingName(const uint16_t maxCharName) {
	// Adding a name process
	std::string name;
	uint16_t countChar;
	bool isNameValid = true;

	while (true) {

		cout << "Enter contact name: ";
		std::getline(std::cin, name);
		cout << "\n";

		while (name.empty()) {
			cout << Log::getError() << "Input empty.\n";
			cout << "Enter contact name: ";
			std::getline(std::cin, name);
			cout << "\n";
		}

		countChar = 0;
		for (char charName : name) { countChar++; }

		if (countChar > maxCharName) {
			cout << Log::getError() << "Name to long.\n";
			cout << Log::getInfo() << "Max character for name: " << maxCharName << "." << "\n";
			cout << "\n\n";
			continue;
		}
		break;


	}
	return name;
}

std::string addNumber(const std::string countryFormat) {
	// Enter phone number process
	std::string number;
	uint16_t formatCountNum = 0;

	while (true) {
		cout << "Enter contact phone number: ";
		std::getline(std::cin, number);
		cout << "\n";

		while (number.empty()) {
			cout << Log::getError() << "Input empty.\n";
			cout << "Enter contact phone number: ";
			std::getline(std::cin, number);
			cout << "\n";
		}

		cleanNumber(number);

		int numberCount = 0;
		for (auto num : number) {
			numberCount++;
		}

		if (countryFormat == "france" || countryFormat == "french") {
			formatCountNum = 10;
		}
		else if (countryFormat == "canada" || countryFormat == "canadien") {
			formatCountNum = 10;
		}
		else if (countryFormat != "france" || countryFormat != "french" || countryFormat != "canada" || countryFormat != "canadien") {
			cout << Log::getError() << "There was an error while processing country format.";
			continue;
		}

		if (numberCount < formatCountNum) {
			cout << Log::getError() << "Number format is not respected.\n";
			continue;
		}
		else if (numberCount > formatCountNum) {
			cout << Log::getError() << "Number format is not respected.\n";
			continue;
		}
		break;
	}
	return number;
}

std::string addCountry() {
	std::string sleep;
	std::string country;
	while (true) {
		cout << "Add country number format.\n";
		cout << "Type 'Canada': Canadien format.\n";
		cout << "Type 'France': French format.\n\n";

		cout << "Format: ";
		std::getline(std::cin, country);

		while (country.empty()) {
			cout << Log::getError() << "Input empty.\n";
			cout << "Enter contact phone number: ";
			std::getline(std::cin, country);
			cout << "\n";
		}

		tolowerc(country);

		if (country.find("canada") != std::string::npos || country.find("canadien") != std::string::npos) {
			return "canada";
		}
		else if (country.find("france") != std::string::npos || country.find("french") != std::string::npos) {
			return "france";
		}
		else {
			cout << "Input invalide.\n";
			std::getline(std::cin, sleep);
			continue;
		}
		break;
	}
}

std::string addMail(const uint16_t maxCharName, const std::array<std::string, 5> domaines) {

	std::string mail;
	uint16_t countChar;

	while (true) {
		cout << "Enter contact mail adress: ";
		std::getline(std::cin, mail);
		cout << "\n";

		while (mail.empty()) {
			cout << Log::getError() << "Input empty.\n";
			cout << "Enter contact mail adress: ";
			std::getline(std::cin, mail);
			cout << "\n";
		}

		countChar = 0;
		for (char mailChar : mail) {
			if (mailChar == '@') {
				break;
			}
			countChar++;
		}

		if (countChar > maxCharName) {
			cout << Log::getError() << "Mail name to long max character before @: " << maxCharName << "\n";
			cout << "----------------\n\n";
			continue;
		}

		std::string mailDomaine = mail.substr(mail.find('@') + 1);
		bool bIsDomaineValid = false;

		for (auto domaine : domaines) {
			if (mailDomaine == domaine) {
				bIsDomaineValid = true;
				break;
			}
		}

		if (bIsDomaineValid == false) {
			cout << "Mail domaine is invalide.";
			cout << "-------------------------";
			continue;
		}
		std::string sleepEnter;
		std::getline(std::cin, sleepEnter);
		break;
	}
	return mail;
}

// Main Adding function added to stack.
void addContact(const uint16_t maxCharName, const std::array<std::string, 5> domaines, Contact& contact, ContactList contactList) {
	std::string name;
	std::string number;
	std::string mail;
	std::string country;

	cout << "######################\n";
	cout << "-- Adding a Contact --\n";
	cout << "######################\n\n";

	name = addingName(maxCharName);

	country = addCountry();

	// const uint16_t maxCountNum, const uint16_t minCountNum
	number = addNumber(country);

	mail = addMail(maxCharName, domaines);

	contact.setName(name);
	contact.setNumber(number);
	contact.setMail(mail);
	contactList.pushContactList(contact.getName(), contact.getNumber(), contact.getMail());



	cout << "Contact added.\n";
	cout << "Name: " << contact.getName() << "\n";
	cout << "Phone number: ";

	printPhoneNumber(country, number);

	cout << "\n";

	cout << "Mail adress: " << contact.getMail() << "\n";
	cout << "\n\n";
}

void printPhoneNumber(const std::string country, const std::string number) {
	uint16_t jumpCount = 0;
	if (country == "french" || country == "france") {
		//std::vector<char> numList;
		for (auto num : number) {
			cout << num;
			jumpCount++;
			if (jumpCount == 2) {
				jumpCount = 0;
				cout << " ";
			}
		}
		jumpCount = 0;
	}
	else if (country == "canada" || country == "canadien") {
		//514 969 8241
		std::string firstDigits = number.substr(0, 3);
		std::string midDigits = number.substr(3, 3);
		std::string lastDigits = number.substr(6, 4);

		std::printf("1+ (%s) %s-%s", firstDigits.c_str(), midDigits.c_str(), lastDigits.c_str());
	}
}
void showContactList(ContactList contactList) {
	std::string sleepEnter;
	cout << "######################\n";
	cout << "-- Contact List --\n";
	cout << "######################\n\n";

	if (contactList.getContactList().size() == 0) {
		cout << "Contact list is empty.\n";
		cout << "Add a new contact to list it here.\n";
		std::getline(std::cin, sleepEnter);
		return;
	}

	uint16_t contactCount = 1;
	for (auto contact : contactList.getContactList()) {
		cout << "Contact " << contactCount << "\n";
		cout << "Name: " << get<0>(contact) << "\n";
		cout << "Phone number: " << get<1>(contact) << "\n";
		cout << "Mail adress: " << get<2>(contact) << "\n\n";
		contactCount++;
	}
	std::getline(std::cin, sleepEnter);
}

void removeContact(ContactList& contactList) {
	cout << "################\n";
	cout << "Remove a Contact\n";
	cout << "################\n\n";

	showContactList(contactList);


}

void cleanNumber(std::string& number) {
	std::string result;
	for (auto num : number) {
		if (isdigit(num)) {
			result += num;
		}
	}
	number = result;
}