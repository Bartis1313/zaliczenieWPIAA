#pragma once

#include <iostream>
#include <ostream>
#include <format>
#include <string>
#include <chrono>
#include <ctime>

// 6. TEMPLATE base
class Logger 
{
public:
    Logger(bool doFlush = false)
        : flushEnabled(doFlush) 
    {

    }

    void log(const std::string& message) 
    {
        std::string formatted = formatMessage(message);
        write(formatted);
        if (flushEnabled)
            flush();
    }

    void setFlushEnabled(bool enabled) { flushEnabled = enabled; }

protected:
    virtual std::string formatMessage(const std::string& msg) 
    {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

        std::tm timeInfo;
#if defined(_WIN32) || defined(_WIN64)
        localtime_s(&timeInfo, &currentTime);
#else
        localtime_r(&currentTime, &timeInfo);
#endif

        char timeString[50];
        std::strftime(timeString, sizeof(timeString), "%d:%m:%Y-%X", &timeInfo);
        return std::format("[{}.{:03}] {}", timeString, static_cast<int>(ms.count()), msg);
    }

    virtual void write(const std::string& formatted) = 0;
    virtual void flush() { }
    virtual ~Logger() = default;

private:
    bool flushEnabled;
};

// 7. COMPOSITE
class CompositeLogger : public Logger 
{
public:
    void addLogger(std::shared_ptr<Logger> logger) 
    {
        loggers.push_back(logger);
    }

protected:
    void write(const std::string& formatted) override 
    {
        for (auto& l : loggers)
            l->log(formatted);
    }

private:
    std::vector<std::shared_ptr<Logger>> loggers;
};