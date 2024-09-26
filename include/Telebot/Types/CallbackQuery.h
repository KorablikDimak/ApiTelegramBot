#ifndef Telebot_CallbackQuery_H
#define Telebot_CallbackQuery_H

#include <Telebot/Types/User.h>
#include <Telebot/Types/Message.h>

namespace Telebot
{
    class CallbackQuery
    {
    public:
        typedef std::shared_ptr<CallbackQuery> Ptr;

        std::string id;
        User::Ptr from;
        Message::Ptr message;
        std::string inline_message_id;
        std::string chat_instance;
        std::string data;
        std::string game_short_name;
    };

    inline void from_json(const ExtendedCpp::Json& json, CallbackQuery& object) noexcept
    {
        VALUE_FROM_JSON(id);
        OBJECT_FROM_JSON(from);
        OBJECT_FROM_JSON(message);
        VALUE_FROM_JSON(inline_message_id);
        VALUE_FROM_JSON(chat_instance);
        VALUE_FROM_JSON(data);
        VALUE_FROM_JSON(game_short_name);
    }
}

#endif