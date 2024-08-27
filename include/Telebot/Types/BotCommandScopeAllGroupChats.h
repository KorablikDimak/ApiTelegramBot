#ifndef Telebot_BotCommandScopeAllGroupChats_H
#define Telebot_BotCommandScopeAllGroupChats_H

#include <Telebot/Types/BotCommandScope.h>

namespace Telebot
{
    class BotCommandScopeAllGroupChats final : public BotCommandScope
    {
    public:
        typedef std::shared_ptr<BotCommandScopeAllGroupChats> Ptr;

        static const std::string TYPE;

        BotCommandScopeAllGroupChats() noexcept
        {
            type = TYPE;
        }
    };
}

#endif