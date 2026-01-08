#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

std::string encryptPassword(const std::string& password, const std::string& key);
std::string decryptPassword(const std::string& encrypted, const std::string& key);

#endif
