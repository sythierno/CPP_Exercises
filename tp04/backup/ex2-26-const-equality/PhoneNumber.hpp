#include <ostream>
#include <string>
#include <vector>
#pragma once

class PhoneNumber
{
private:
    std::vector<int> _nbrs = std::vector<int>(5);

public:
    PhoneNumber(int un, int deux, int trois, int quatre, int cinq)
    {
        _nbrs[0] = un;
        _nbrs[1] = deux;
        _nbrs[2] = trois;
        _nbrs[3] = quatre;
        _nbrs[4] = cinq;
    };

    bool is_valid() const
    {
        for (int i = 0; i < 5; i++)
        {
            if (_nbrs[i] < 0 || _nbrs[i] > 99)
            {
                return false;
            }
        }
        return true;
    }

    int operator[](int index) const
    {
        if (index >= 0 && index < 5)
        {
            return _nbrs[index];
        }
        return -1;
    }

    friend std::ostream& operator<<(std::ostream& op, const PhoneNumber& phone)
    {
        auto result = std::string();
        for (int i = 0; i < 5; i++)
        {
            auto toAdd = std::to_string(phone[i]);
            if (toAdd.length() == 1)
            {
                toAdd = "0" + toAdd;
            }
            result += toAdd;
        }
        return op << result;
    }
};
