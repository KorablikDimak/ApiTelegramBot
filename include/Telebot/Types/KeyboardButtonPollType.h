#ifndef Telebot_KeyboardButtonPollType_H
#define Telebot_KeyboardButtonPollType_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class KeyboardButtonPollType
    {
    public:
        typedef std::shared_ptr<KeyboardButtonPollType> Ptr;

        std::string type;
    };

    inline void to_json(ExtendedCpp::Json& json, const KeyboardButtonPollType::Ptr& object) noexcept
    {
        VALUE_TO_JSON(type)
    }
}

#endif