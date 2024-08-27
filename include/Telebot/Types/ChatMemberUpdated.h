#ifndef Telebot_ChatMemberUpdated_H
#define Telebot_ChatMemberUpdated_H

#include <Telebot/Types/Chat.h>
#include <Telebot/Types/User.h>
#include <Telebot/Types/ChatMember.h>
#include <Telebot/Types/ChatInviteLink.h>

namespace Telebot
{
    class ChatMemberUpdated
    {
    public:
        typedef std::shared_ptr<ChatMemberUpdated> Ptr;

        Chat::Ptr chat;
        User::Ptr from;
        std::uint32_t date;
        ChatMember::Ptr old_chat_member;
        ChatMember::Ptr new_chat_member;
        ChatInviteLink::Ptr invite_link;
    };

    inline void from_json(const Json::Json& json, ChatMemberUpdated& object) noexcept
    {
        OBJECT_FROM_JSON(chat)
        OBJECT_FROM_JSON(from)
        VALUE_FROM_JSON(date)
        OBJECT_FROM_JSON(old_chat_member)
        OBJECT_FROM_JSON(new_chat_member)
        OBJECT_FROM_JSON(invite_link)
    }
}

#endif