#ifndef Telebot_ChatMemberBanned_H
#define Telebot_ChatMemberBanned_H

#include <Telebot/Types/ChatMember.h>

namespace Telebot
{
    class ChatMemberBanned final : public ChatMember
    {
    public:
        typedef std::shared_ptr<ChatMemberBanned> Ptr;

        static const std::string STATUS;

        ChatMemberBanned() noexcept
        {
            status = STATUS;
        }

        std::int32_t UntilDate{};
    };
}

#endif