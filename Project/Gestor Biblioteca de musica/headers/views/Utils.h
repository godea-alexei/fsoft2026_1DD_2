#ifndef UTILS_H
#define UTILS_H
#endif //UTILS_H
#include <string>

class Util {
public:
    static float getFloat(const std::string& s);
    static bool getBool(const std::string& s);
    static bool validarUser(const std::string& s);
    static bool validarPass(const std::string& s);
    static std::string getString(const std::string& s);
    static int getNumber(const std::string& s);
};
