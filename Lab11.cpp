#include <iostream>
#include <string>
#include <regex>

using namespace std;

struct Currency {
    string name;
    double exchangeRate;
    string currencyCode;

    Currency(const string& n, double rate, const string& code) : name(n), exchangeRate(rate), currencyCode(code) {}

    double convertToUAH(double amount) const {
        regex currencyCodeRegex("[A-Z]{3}");

        if (regex_match(currencyCode, currencyCodeRegex)) {
            return amount * exchangeRate;
        } else {
            cerr << "Невірний код валюти: " << currencyCode << endl;
            return 0.0;
        }
    }
};

int main() {
    string name, code;
    double rate;

    cout << "Введіть назву валюти: ";
    getline(cin, name);

    cout << "Введіть обмінний курс до гривні: ";
    cin >> rate;

    cout << "Введіть код валюти (3 великі літери): ";
    cin >> code;

    Currency currency(name, rate, code);

    double amount;
    cout << "Введіть суму для конвертації: ";
    cin >> amount;

    double result = currency.convertToUAH(amount);
    cout << amount << " " << currency.currencyCode << " = " << result << " грн" << endl;

    return 0;
}
