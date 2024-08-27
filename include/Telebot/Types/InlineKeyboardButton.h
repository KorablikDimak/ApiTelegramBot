#ifndef Telebot_InlineKeyboardButton_H
#define Telebot_InlineKeyboardButton_H

#include <Telebot/Types/WebAppInfo.h>
#include <Telebot/Types/LoginUrl.h>
#include <Telebot/Types/CallbackGame.h>

namespace Telebot
{
    class InlineKeyboardButton
    {
    public:
        typedef std::shared_ptr<InlineKeyboardButton> Ptr;

        InlineKeyboardButton() = default;

        InlineKeyboardButton(const std::string& text, const std::string& callbackData) noexcept
        {
            this->text = text;
            this->callback_data = callbackData;
        }

        std::string text;
        std::string url;
        std::string callback_data;
        WebAppInfo::Ptr web_app;
        LoginUrl::Ptr login_url;
        std::string switch_inline_query;
        std::string switch_inline_query_current_chat;
        CallbackGame::Ptr callback_game;
        bool pay{};
    };

    inline void from_json(const Json::Json& json, InlineKeyboardButton& object) noexcept
    {
        VALUE_FROM_JSON(text)
        VALUE_FROM_JSON(url)
        VALUE_FROM_JSON(callback_data)
        OBJECT_FROM_JSON(web_app)
        OBJECT_FROM_JSON(login_url)
        VALUE_FROM_JSON(switch_inline_query)
        VALUE_FROM_JSON(switch_inline_query_current_chat)
        OBJECT_FROM_JSON(callback_game)
        VALUE_FROM_JSON(pay)
    }

    inline void to_json(Json::Json& json, const InlineKeyboardButton::Ptr& object) noexcept
    {
        VALUE_TO_JSON(text)
        if (!object->url.empty()) VALUE_TO_JSON(url)
        if (!object->callback_data.empty()) VALUE_TO_JSON(callback_data)
        OBJECT_TO_JSON(web_app)
        OBJECT_TO_JSON(login_url)
        VALUE_TO_JSON(switch_inline_query)
        VALUE_TO_JSON(switch_inline_query_current_chat)
        OBJECT_TO_JSON(callback_game)
        VALUE_TO_JSON(pay)
    }
}

#define INLINE_BUTTON(text, callbackData) \
std::make_shared<Telebot::InlineKeyboardButton>(text, callbackData)

#endif