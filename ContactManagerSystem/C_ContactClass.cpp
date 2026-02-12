#include <string>
#include <vector>
#include <tuple>
#include "C_ContactClass.h"


// LOG LOG LOG LOG
// Definition of Log m_Variables.
const std::string Log::m_Warning = "[WARNING]: ";
const std::string Log::m_Error = "[ERROR]: ";
const std::string Log::m_Info = "[INFO]: ";
// Definition of Log getters.
std::string Log::getWarn() { return m_Warning; }
std::string Log::getError() { return m_Error; }
std::string Log::getInfo() { return m_Info; }



// CONTACT  CONTACT CONTACT CONTACT
// Definition of Class Contact getters.
std::string Contact::getName() { return m_Name; }
std::string Contact::getNumber() { return m_Number; }
std::string Contact::getMail() { return m_Mail; }
// Definition of Class Contact setters.
void Contact::setName(std::string name) { this->m_Name = name; }
void Contact::setNumber(std::string number) { this->m_Number = number; }
void Contact::setMail(std::string mail) { this->m_Mail = mail; }



// CONTACTLIST CONTACTLIST CONTACTLIST CONTACTLIST
// Definition of Class ContactList m_Variables
std::vector<std::tuple<std::string, std::string, std::string>> ContactList::m_ContactList;
// Definition of Class ContactList getters
std::vector<std::tuple<std::string, std::string, std::string>> ContactList::getContactList() { return m_ContactList; }
void ContactList::pushContactList(std::string name, std::string number, std::string mail) {
	m_ContactList.push_back({ name, number, mail });
}
auto ContactList::begin() { return ContactList::m_ContactList.begin(); }
auto ContactList::end() { return ContactList::m_ContactList.end(); }
auto ContactList::erase(size_t index) {
	if (index < ContactList::m_ContactList.size()) {
		return ContactList::m_ContactList.erase(ContactList::m_ContactList.begin() + index);
	}
	return ContactList::m_ContactList.end();
}