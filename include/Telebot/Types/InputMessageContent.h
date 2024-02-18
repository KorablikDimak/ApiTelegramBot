#ifndef Telebot_InputMessageContent_H
#define Telebot_InputMessageContent_H

#include <memory>
#include <string>

namespace Telebot
{
    class InputMessageContent
    {
    public:
        typedef std::shared_ptr<InputMessageContent> Ptr;

        InputMessageContent() = default;
        virtual ~InputMessageContent() = default;

        std::string Type;
    };
}

#endif