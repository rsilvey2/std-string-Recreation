#pragma once
#ifndef CS23001_STRING_INTERFACE_HPP
#define CS23001_STRING_INTERFACE_HPP

#include <iostream>
#include <vector>

////////////////////////////////////////////////////
// CLASS INV: str[length()] == 0             &&
//            length()      == capacity()    &&
//            capacity()    == stringSize - 1
//

class String {
public:
    String();                               //Empty string
    String(char);                           //String('x')
    String(const char[]);                   //String("abc")
    String(const String&);                  //Copy Constructor
    ~String();                              //Destructor
    void    swap(String&);                        //Constant time swap
    String& operator=     (String);                         //Assignment Copy
    char& operator[]    (int);                            //Accessor/Modifier
    char    operator[]    (int)                     const;  //Accessor
    int     capacity()                        const;  //Max chars that can be stored (not including null)
    int     length()                        const;  //Actual number of chars in string
    String  operator+     (const String&)           const;
    String& operator+=    (const String&);
    bool    operator==    (const String&)           const;
    bool    operator<     (const String&)           const;
    String  substr(int, int)                const;  //The sub-string from staring position to ending position
    int     findch(int, char)               const;  //Find location of character starting at a position
    int     findstr(int, const String&)     const;  //Find location of str starting at a position
    int     strToInt()                      const;  //converts String to int 

    friend  std::ostream& operator<<(std::ostream&, const String&);
    friend  std::istream& operator>>(std::istream&, String&);

    std::vector<String> split(char) const;      //This method will return a vector of String split up based on a supplied character.

private:

    String(int);                            //String(10) - capacity 10, empty string
    String(int, const char[]);              //String(10, "abc") - capacity 10 with "abc"

    void    resetCapacity(int);                          //Resets capacity to N, keeps string intact

    char* str;                                           //Pointer to char[]
    int     stringSize;                                     //Size includes NULL terminator
};

String toString(const int);

String  operator+       (const char[], const String&);
String  operator+       (char, const String&);
bool    operator==      (const char[], const String&);
bool    operator==      (char, const String&);
bool    operator<       (const char[], const String&);
bool    operator<       (char, const String&);
bool    operator<=      (const String&, const String&);
bool    operator!=      (const String&, const String&);
bool    operator>=      (const String&, const String&);
bool    operator>       (const String&, const String&);

#endif
