#pragma once
#include <vector>
#include <tuple>
#include <string>

class Log {
private:
	static const std::string m_Warning;
	static const std::string m_Error;
	static const std::string m_Info;
public:
	static std::string getWarn();
	static std::string getError();
	static std::string getInfo();
};

class Contact {
private:
	std::string m_Name;
	std::string m_Number;
	std::string m_Mail;
	std::string m_Country;
public:
	std::string getName();
	std::string getNumber();
	std::string getMail();

	void setName(std::string name);
	void setNumber(std::string number);
	void setMail(std::string mail);
};

class ContactList {
private:
	static std::vector<std::tuple<std::string, std::string, std::string>> m_ContactList;
public:
	static std::vector<std::tuple<std::string, std::string, std::string>> getContactList();

	static void pushContactList(std::string name, std::string number, std::string mail);

	static auto begin();
	static auto end();

	static auto erase(size_t index);
};