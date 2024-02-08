
#ifndef BASICOPPERATION_H
#define BASICOPPERATION_H


#include <list>
#include <memory>
#include <string>
#include <vector>

#include "atomType.h"

namespace calculus
{

    std::string *add(const std::string &left, const std::string &right)
    {
        std::unique_ptr<std::string> result() = new std::string;
    }


}

#endif //BASICOPPERATION_H
