#ifndef Telebot_InputContactMessageContent_H
#define Telebot_InputContactMessageContent_H

#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InputContactMessageContent final : public InputMessageContent
    {
    public:
        typedef std::shared_ptr<InputContactMessageContent> Ptr;

        static const std::string TYPE;

        InputContactMessageContent()
        {
            Type = TYPE;
        }

        std::string PhoneNumber;
        std::string FirstName;
        std::string LastName;
        std::string Vcard;
    };
}

#endif