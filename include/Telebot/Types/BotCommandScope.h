#ifndef Telebot_BotCommandScope_H
#define Telebot_BotCommandScope_H

#include <ExtendedCpp/Json.h>

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

    inline void to_json(ExtendedCpp::Json& json, const BotCommandScope::Ptr& object) noexcept
    {
        VALUE_TO_JSON(type)
    }
}

#endif