#include <iostream>
#include <cstring>

/**
 * @brief Generate a random 5-letter key
 * @return std::string: the generated key
*/
std::string generateKey() {
    std::string key;
    const int length{5};
    static const char alphabet[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int alphabetLength = strlen(alphabet);

    for (int i = 0; i < length; ++i) {
        char c = alphabet[rand() % alphabetLength];
        key += c;
    }

    return key;
}