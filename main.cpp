#include <iostream>
#include <string>

using namespace std;

int ConvertRomanNumerals(string numRoman);
string ConvertModernNumbers(int numModern);

int main() {
    string romanNumerals;
    int modernNumbers = 0;
    char userChar = 'a';

    while (userChar != 'e') {
        cout << "If you would like to convert Roman numerals to modern numbers, press r." << endl;
        cout << "If you would like to convert modern numbers to Roman numerals, press m." << endl;
        cout << "If you would like to end the program, press e." << endl;
        cout << "Press any other key to see the options again." << endl;

        cin  >> userChar;

        //Roman Numerals to Modern numbers
        if (userChar == 'r') {
            cout << "Input Roman numerals. When you are done, press enter." << endl;
            cin  >> romanNumerals;
            cout << endl;

            modernNumbers = ConvertRomanNumerals(romanNumerals);

            cout << romanNumerals << " in modern numbers is " << modernNumbers << "." << endl;

            cout << "If you would like to convert something else, press c. Otherwise, press e to end the program." << endl;
            cin  >> userChar;
        }

        //Modern numbers to Roman numerals
        else if (userChar == 'm') {
            cout << "Input modern numbers without any commas or spaces. When you are done, press enter." << endl;
            cin  >> modernNumbers;
            cout << endl;

            romanNumerals = ConvertModernNumbers(modernNumbers);

            cout << modernNumbers << " in Roman numerals is " << romanNumerals << "." << endl;

            cout << "If you would like to convert something else, press c. Otherwise, press e to end the program." << endl;
            cin  >> userChar;
        }
    }
    return 0;
}

int RomanNumeralValue(char romNumeral) {
    if (romNumeral == 'I') {
        return 1;
    }
    if (romNumeral == 'V') {
        return 5;
    }
    if (romNumeral == 'X') {
        return 10;
    }
    if (romNumeral == 'L') {
        return 50;
    }
    if (romNumeral == 'C') {
        return 100;
    }
    if (romNumeral == 'D') {
        return 500;
    }
    if (romNumeral == 'M') {
        return 1000;
    }
    else {
        return 0;
    }
}

int ConvertRomanNumerals(string numRoman) {
    int totalValue = 0;
    int romValue = 0;
    int nextRom = 0;

    for (int i = 0; i < numRoman.length(); i++) {
        romValue = RomanNumeralValue(numRoman[i]);

            if (i + 1 < numRoman.length()) {
                nextRom = RomanNumeralValue(numRoman[i+1]);

                if (romValue >= nextRom) {
                    totalValue += romValue;
                }
                else {
                    totalValue += nextRom - romValue;
                    i++;
                }
            }
            else {
            totalValue += romValue;
        }
    }
    return totalValue;
}

string ConvertModernNumbers(int numModern) {
    string romNumeral;
    while (numModern > 0) {
        if (numModern / 1000) {
            romNumeral += "M";
            numModern -= 1000;
        }
        if (numModern / 900) {
            romNumeral += "CM";
            numModern -= 900;
        }
        if (numModern / 500) {
            romNumeral += "D";
            numModern -= 500;
        }
        if (numModern / 400) {
            romNumeral += "CD";
            numModern -= 400;
        }
        if (numModern / 100) {
            romNumeral += "C";
            numModern -= 100;
        }
        if (numModern / 90) {
            romNumeral += "XC";
            numModern -= 90;
        }
        if (numModern / 50) {
            romNumeral += "L";
            numModern -= 50;
        }
        if (numModern / 40) {
            romNumeral += "XL";
            numModern -= 40;
        }
        else if (numModern / 10) {
            romNumeral += "X";
            numModern -= 10;
        }
        else if (numModern / 9) {
            romNumeral += "IX";
            numModern -= 9;
        }
        else if (numModern / 5) {
            romNumeral += "V";
            numModern -= 5;
        }
        else if (numModern / 4) {
            romNumeral += "IV";
            numModern -= 4;
        }
        else if (numModern / 1) {
            romNumeral += "I";
            numModern -= 1;
        }
    }
    return romNumeral;
}