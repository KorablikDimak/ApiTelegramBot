#ifndef Telebot_KeyboardButtonPollType_H
#define Telebot_KeyboardButtonPollType_H

#include <Json/Json.h>

namespace Telebot
{
    class KeyboardButtonPollType
    {
    public:
        typedef std::shared_ptr<KeyboardButtonPollType> Ptr;

        std::string type;
    };

    inline void to_json(Json::Json& json, const KeyboardButtonPollType::Ptr& object)
    {
        VALUE_TO_JSON(type)
    }
}

#endif