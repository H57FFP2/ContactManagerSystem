#pragma once
#include "C_ContactClass.h"

// Addind a contact function.
void addContact(const uint16_t maxCharName, const std::array<std::string, 5> domaines, Contact& contact, ContactList contactList);

// Show contact list function.
void showContactList(ContactList contactList);

// Remove a contact function.
void removeContact(ContactList& contactList);

// Function wich removes not necessary characters and keep only numbers.
void cleanNumber(std::string& number);

//Funtion to print correctly number format based on country phone number format.
void printPhoneNumber(const std::string country, const std::string number);