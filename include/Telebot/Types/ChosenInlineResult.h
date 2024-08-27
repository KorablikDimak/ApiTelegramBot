#ifndef Telebot_ChosenInlineResult_H
#define Telebot_ChosenInlineResult_H

#include <Telebot/Types/User.h>
#include <Telebot/Types/Location.h>

namespace Telebot
{
    class ChosenInlineResult
    {
    public:
        typedef std::shared_ptr<ChosenInlineResult> Ptr;

        std::string result_id;
        User::Ptr from;
        Location::Ptr location;
        std::string inline_message_id;
        std::string query;
    };

    inline void from_json(const Json::Json& json, ChosenInlineResult& object) noexcept
    {
        VALUE_FROM_JSON(result_id)
        OBJECT_FROM_JSON(from)
        OBJECT_FROM_JSON(location)
        VALUE_FROM_JSON(inline_message_id)
        VALUE_FROM_JSON(query)
    }
}

#endif