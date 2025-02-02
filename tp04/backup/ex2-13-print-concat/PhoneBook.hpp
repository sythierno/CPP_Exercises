#pragma once
#include "PhoneBookEntry.hpp"

#include <list>
#include <string>

class PhoneBook
{
private:
    std::list<PhoneBookEntry> _phoneBooks;

public:
    bool add_entry(PhoneBookEntry phoneBook)
    {
        if (!phoneBook.isValid())
        {

            return false;
        }
        for (auto& _phoneBook : _phoneBooks)
        {
            if (_phoneBook == phoneBook)
            {
                return false;
            }
        }
        _phoneBooks.emplace_back(phoneBook);
        return true;
    }

    const PhoneNumber* get_number(std::string const name) const
    {

        for (auto& phoneBook : _phoneBooks)
        {
            if (phoneBook.get_name() == name)
            {
                return phoneBook.getPhoneNumber();
            }
        }
        return nullptr;
    }
};