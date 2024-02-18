#ifndef Telebot_BotCommandScopeChatMember_H
#define Telebot_BotCommandScopeChatMember_H

#include <Telebot/Types/BotCommandScope.h>

namespace Telebot
{
    class BotCommandScopeChatMember final : public BotCommandScope
    {
    public:
        typedef std::shared_ptr<BotCommandScopeChatMember> Ptr;

        static const std::string TYPE;

        BotCommandScopeChatMember()
        {
            type = TYPE;
        }

        std::int64_t ChatId;
        std::int64_t UserId;
    };
}

#endif