#ifndef Telebot_BotCommandScopeChat_H
#define Telebot_BotCommandScopeChat_H

#include <Telebot/Types/BotCommandScope.h>

namespace Telebot
{
    class BotCommandScopeChat final : public BotCommandScope
    {
    public:
        typedef std::shared_ptr<BotCommandScopeChat> Ptr;

        static const std::string TYPE;

        BotCommandScopeChat()
        {
            type = TYPE;
        }

        std::int64_t ChatId;
    };
}

#endif