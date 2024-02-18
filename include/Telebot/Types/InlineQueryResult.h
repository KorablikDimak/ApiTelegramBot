#ifndef Telebot_InlineQueryResult_H
#define Telebot_InlineQueryResult_H

#include <Telebot/Types/InlineKeyboardMarkup.h>

namespace Telebot
{
    class InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResult> Ptr;

        InlineQueryResult() = default;
        virtual ~InlineQueryResult() = default;

        std::string Type;
        std::string Id;
        InlineKeyboardMarkup::Ptr ReplyMarkup;
    };
}

#endif