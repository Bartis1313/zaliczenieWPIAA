#pragma once

#include "logger.hpp"

// 6. TEMPLATE 
class ConsoleLogger : public Logger 
{
public:
    ConsoleLogger(bool doFlush = false)
        : Logger(doFlush)
    {

    }

protected:
    void write(const std::string& formatted) override 
    {
        std::cout << formatted << '\n';
    }

    void flush() override
    {
        std::cout << std::flush;
    }
};