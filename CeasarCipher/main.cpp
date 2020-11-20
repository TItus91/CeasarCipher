#include <iostream>
#include <vector>
#include <string>



class CaesarCipher
{


public:
    static std::vector<std::string> movingShift(const std::string& s, int shift)
    {
        std::string string1, string2, string3, string4, string5;
        std::vector<std::string> MyVector{ string1, string2, string3, string4, string5 };
        std::string temp;
        temp.reserve(s.size());

        for (int i = 0; i < s.size(); i++)
        {
            temp.push_back(s[i]);
            if (temp.back() > 64 && temp.back() < 91)
            {
                unsigned int x = s[i] + shift + i;
                while (x > 90) x -= 26;
                temp.back() = x;
            }
            else if (temp.back() > 96 && temp.back() < 123)
            {
                unsigned int x = s[i] + shift + i;
                while (x > 122) x -= 26;
                temp.back() = x;
            }
        }
        int t = 0;
        while (!temp.empty())
        {
            if (s.size() % 5 == 0)
            {
                for (int i = 0; i < s.size() / 5; i++)
                {
                    MyVector[t].push_back(temp.front());
                    temp.erase(0, 1);
                }
                t++;
            }
            else if (s.size() == 6)
            {
                MyVector[0] = temp.substr(0, 2);
                MyVector[1] = temp.substr(2, 2);
                MyVector[2] = temp.substr(4, 1);
                MyVector[3] = temp.substr(5, 1);
                temp.clear();
            }
            else if (s.size() == 7)
            {
                MyVector[0] = temp.substr(0, 2);
                MyVector[1] = temp.substr(2, 2);
                MyVector[2] = temp.substr(4, 2);
                MyVector[3] = temp.substr(6, 1);
                temp.clear();
            }
            else if (s.size() == 11)
            {
                MyVector[0] = temp.substr(0, 3);
                MyVector[1] = temp.substr(3, 3);
                MyVector[2] = temp.substr(6, 3);
                MyVector[3] = temp.substr(9, 2);
                temp.clear();
            }
            else 
            {
                for (int i = 0; i < s.size()/5+1; i++)
                {
                    if (!temp.empty()) 
                    {
                        MyVector[t].push_back(temp.front());
                        temp.erase(0, 1);
                    }
                }
                t++;
            }
        }

        return MyVector;
    }

    static std::string demovingShift(std::vector<std::string>& s, int shift)
    {
        std::string Stiched;
        Stiched = s[0] + s[1] + s[2] + s[3] + s[4];

        for (int i = 0; i < Stiched.size(); i++)
        {
            if (Stiched[i] > 64 && Stiched[i]< 91)
            {
                Stiched[i] -= (shift + i);
                while (Stiched[i] < 65) Stiched[i] += 26;
            }
            else if (Stiched[i] > 96 && Stiched[i] < 123)
            {
                Stiched[i] -= (shift + i);
                while (Stiched[i] < 97) Stiched[i] += 26;
            }
        }
        return Stiched;
    }
    
};




int main()
{

    // zmiana w github
    //cos tam jeszcze dopisze

}
