#ifndef ACCURACY_HELPER_HPP
#define ACCURACY_HELPER_HPP

#include <string>

class AccuracyHelper
{
  
public:
    AccuracyHelper() noexcept {}
    ~AccuracyHelper() {}
    static double calculateAccuracy(const std::string &m1File,  // first layer filename
                    const std::string &m2File,  // second layer filename
                    const std::string testFile); // test filename
};





#endif