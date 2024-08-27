#ifndef Telebot_ChatMember_H
#define Telebot_ChatMember_H

#include <Telebot/Types/User.h>

namespace Telebot
{
    class ChatMember
    {
    public:
        typedef std::shared_ptr<ChatMember> Ptr;

        ChatMember() = default;
        virtual ~ChatMember() = default;

        std::string status;
        User::Ptr user;
    };

    inline void from_json(const Json::Json& json, ChatMember& object) noexcept
    {
        VALUE_FROM_JSON(status)
        OBJECT_FROM_JSON(user)
    }
}

#endif