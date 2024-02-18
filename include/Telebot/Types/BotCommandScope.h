#ifndef Telebot_BotCommandScope_H
#define Telebot_BotCommandScope_H

#include <Json/Json.h>

namespace Telebot
{
    class BotCommandScope
    {
    public:
        typedef std::shared_ptr<BotCommandScope> Ptr;

        BotCommandScope() = default;
        virtual ~BotCommandScope() = default;

        std::string type;
    };

    inline void to_json(Json::Json& json, const BotCommandScope::Ptr& object)
    {
        VALUE_TO_JSON(type)
    }
}

#endif