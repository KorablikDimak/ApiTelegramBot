#ifndef Telebot_KeyboardButton_H
#define Telebot_KeyboardButton_H

#include <Telebot/Types/KeyboardButtonRequestUser.h>
#include <Telebot/Types/KeyboardButtonRequestChat.h>
#include <Telebot/Types/KeyboardButtonPollType.h>
#include <Telebot/Types/WebAppInfo.h>

namespace Telebot
{
    class KeyboardButton
    {
    public:
        typedef std::shared_ptr<KeyboardButton> Ptr;

        std::string text;
        KeyboardButtonRequestUser::Ptr request_user;
        KeyboardButtonRequestChat::Ptr request_chat;
        bool request_contact;
        bool request_location;
        KeyboardButtonPollType::Ptr request_poll;
        WebAppInfo::Ptr web_app;
    };

    inline void to_json(Json::Json& json, const KeyboardButton::Ptr& object) noexcept
    {
        VALUE_TO_JSON(text)
        OBJECT_TO_JSON(request_user)
        OBJECT_TO_JSON(request_chat)
        VALUE_TO_JSON(request_contact)
        VALUE_TO_JSON(request_location)
        OBJECT_TO_JSON(request_poll)
        OBJECT_TO_JSON(web_app)
    }
}

#endif