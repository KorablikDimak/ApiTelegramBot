#ifndef Telebot_PassportElementError_H
#define Telebot_PassportElementError_H

#include <memory>
#include <string>

namespace Telebot
{
    class PassportElementError
    {
    public:
        typedef std::shared_ptr<PassportElementError> Ptr;

        PassportElementError() = default;
        virtual ~PassportElementError() = default;

        std::string Source;
        std::string Type;
        std::string Message;
    };
}

#endif