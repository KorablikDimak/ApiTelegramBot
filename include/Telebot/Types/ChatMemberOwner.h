#ifndef Telebot_ChatMemberOwner_H
#define Telebot_ChatMemberOwner_H

#include <Telebot/Types/ChatMember.h>

namespace Telebot
{
    class ChatMemberOwner final : public ChatMember
    {
    public:
        typedef std::shared_ptr<ChatMemberOwner> Ptr;

        static const std::string STATUS;

        ChatMemberOwner() noexcept
        {
            status = STATUS;
        }

        std::string CustomTitle;
        bool IsAnonymous{};
    };
}

#endif