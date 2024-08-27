#ifndef Telebot_ChatMemberLeft_H
#define Telebot_ChatMemberLeft_H

#include <Telebot/Types/ChatMember.h>

namespace Telebot
{
    class ChatMemberLeft final : public ChatMember
    {
    public:
        typedef std::shared_ptr<ChatMemberLeft> Ptr;

        static const std::string STATUS;

        ChatMemberLeft() noexcept
        {
            status = STATUS;
        }
    };
}

#endif