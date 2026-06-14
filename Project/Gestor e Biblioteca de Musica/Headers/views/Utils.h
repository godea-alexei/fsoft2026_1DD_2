#ifndef UTILS_H
#define UTILS_H
#include <string>



class Utils {
public:

    static std::string getString(const std::string& s);
    static int getNumber(const std::string& s);
    static void printMessage(std::string& msg);

};




#endif //UTILS_H