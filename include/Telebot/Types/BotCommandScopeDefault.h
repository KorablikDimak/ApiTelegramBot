#ifndef Telebot_BotCommandScopeDefault_H
#define Telebot_BotCommandScopeDefault_H

#include <Telebot/Types/BotCommandScope.h>

namespace Telebot
{
    class BotCommandScopeDefault final : public BotCommandScope
    {
    public:
        typedef std::shared_ptr<BotCommandScopeDefault> Ptr;

        static const std::string TYPE;

        BotCommandScopeDefault() noexcept
        {
            type = TYPE;
        }
    };
}

#endif