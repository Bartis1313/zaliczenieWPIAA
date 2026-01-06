#pragma once

#include "logger.hpp"

#include <fstream>>

// 6. TEMPLATE 
class FileLogger : public Logger 
{
public:
    FileLogger(const std::string& filename, bool doFlush = false)
        : Logger(doFlush), file{ filename, std::ios::app }
    {
        
    }

protected:
    void write(const std::string& formatted) override 
    {
        file << formatted << '\n';
    }

    void flush() override 
    {
        file.flush();
    }

private:
    std::ofstream file;
};