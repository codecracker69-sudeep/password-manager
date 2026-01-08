#include "encryption.h"

std::string encryptPassword(const std::string& password, const std::string& key) {
    std::string encrypted = password;
    for (size_t i = 0; i < password.size(); i++) {
        encrypted[i] = password[i] ^ key[i % key.size()];
    }
    return encrypted;
}

std::string decryptPassword(const std::string& encrypted, const std::string& key) {
    std::string decrypted = encrypted;
    for (size_t i = 0; i < encrypted.size(); i++) {
        decrypted[i] = encrypted[i] ^ key[i % key.size()];
    }
    return decrypted;
}
