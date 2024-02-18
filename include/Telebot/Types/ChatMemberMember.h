#ifndef Telebot_ChatMemberMember_H
#define Telebot_ChatMemberMember_H

#include <Telebot/Types/ChatMember.h>

namespace Telebot
{
    class ChatMemberMember final : public ChatMember
    {
    public:
        typedef std::shared_ptr<ChatMemberMember> Ptr;

        static const std::string STATUS;

        ChatMemberMember()
        {
            status = STATUS;
        }
    };
}

#endif