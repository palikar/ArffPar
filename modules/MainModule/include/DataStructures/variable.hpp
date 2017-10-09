//
// Created by stanislav on 10/7/17.
//

#pragma once

#include <string>
#include <limits>
#include <boost/unordered/unordered_map.hpp>
#include <boost/any.hpp>

namespace data_works
{

    class Variable
    {
    public:
        Variable(const std::string &name);

        Variable(const Variable &obj);

        ~Variable();


        virtual bool isValueAllowed(const std::string &val) const = 0;

        const std::string &getName() const;

    private:
        std::string name_;
        boost::unordered_map<std::string, boost::any> params_;

    };
}

