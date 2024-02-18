#ifndef Telebot_BotCommandScopeAllChatAdministrators_H
#define Telebot_BotCommandScopeAllChatAdministrators_H

#include <Telebot/Types/BotCommandScope.h>

namespace Telebot
{
    class BotCommandScopeAllChatAdministrators final : public BotCommandScope
    {
    public:
        typedef std::shared_ptr<BotCommandScopeAllChatAdministrators> Ptr;

        static const std::string TYPE;

        BotCommandScopeAllChatAdministrators()
        {
            type = TYPE;
        }
    };
}

#endif