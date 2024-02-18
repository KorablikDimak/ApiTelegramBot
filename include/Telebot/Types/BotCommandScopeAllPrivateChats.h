#ifndef Telebot_BotCommandScopeAllPrivateChats_H
#define Telebot_BotCommandScopeAllPrivateChats_H

#include <Telebot/Types/BotCommandScope.h>

namespace Telebot
{
    class BotCommandScopeAllPrivateChats final : public BotCommandScope
    {
    public:
        typedef std::shared_ptr<BotCommandScopeAllPrivateChats> Ptr;

        static const std::string TYPE;

        BotCommandScopeAllPrivateChats()
        {
            type = TYPE;
        }
    };
}

#endif