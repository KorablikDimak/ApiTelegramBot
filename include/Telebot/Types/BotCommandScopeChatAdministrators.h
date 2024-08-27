#ifndef Telebot_BotCommandScopeChatAdministrators_H
#define Telebot_BotCommandScopeChatAdministrators_H

#include <Telebot/Types/BotCommandScope.h>

namespace Telebot
{
    class BotCommandScopeChatAdministrators final : public BotCommandScope
    {
    public:
        typedef std::shared_ptr<BotCommandScopeChatAdministrators> Ptr;

        static const std::string TYPE;

        BotCommandScopeChatAdministrators() noexcept
        {
            type = TYPE;
        }

        std::int64_t ChatId{};
    };
}

#endif