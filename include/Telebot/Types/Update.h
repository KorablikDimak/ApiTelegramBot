#ifndef Telebot_Update_H
#define Telebot_Update_H

#include <Telebot/Types/Message.h>
#include <Telebot/Types/InlineQuery.h>
#include <Telebot/Types/ChosenInlineResult.h>
#include <Telebot/Types/CallbackQuery.h>
#include <Telebot/Types/ShippingQuery.h>
#include <Telebot/Types/PreCheckoutQuery.h>
#include <Telebot/Types/Poll.h>
#include <Telebot/Types/PollAnswer.h>
#include <Telebot/Types/ChatMemberUpdated.h>
#include <Telebot/Types/ChatJoinRequest.h>

namespace Telebot
{
    class Update
    {
    public:
        typedef std::shared_ptr<Update> Ptr;

        std::int32_t update_id;
        Message::Ptr message;
        Message::Ptr edited_message;
        Message::Ptr channel_post;
        Message::Ptr edited_channel_post;
        InlineQuery::Ptr inline_query;
        ChosenInlineResult::Ptr chosen_inline_result;
        CallbackQuery::Ptr callback_query;
        ShippingQuery::Ptr shipping_query;
        PreCheckoutQuery::Ptr pre_checkout_query;
        Poll::Ptr poll;
        PollAnswer::Ptr poll_answer;
        ChatMemberUpdated::Ptr my_chat_member;
        ChatMemberUpdated::Ptr chat_member;
        ChatJoinRequest::Ptr chat_join_request;
    };

    inline void from_json(const Json::Json& json, Update& object)
    {
        VALUE_FROM_JSON(update_id)
        OBJECT_FROM_JSON(message)
        OBJECT_FROM_JSON(edited_message)
        OBJECT_FROM_JSON(channel_post)
        OBJECT_FROM_JSON(edited_channel_post)
        OBJECT_FROM_JSON(inline_query)
        OBJECT_FROM_JSON(chosen_inline_result)
        OBJECT_FROM_JSON(callback_query)
        OBJECT_FROM_JSON(shipping_query)
        OBJECT_FROM_JSON(pre_checkout_query)
        OBJECT_FROM_JSON(poll)
        OBJECT_FROM_JSON(poll_answer)
        OBJECT_FROM_JSON(my_chat_member)
        OBJECT_FROM_JSON(chat_member)
        OBJECT_FROM_JSON(chat_join_request)
    }
}

#endif