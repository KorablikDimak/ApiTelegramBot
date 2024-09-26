#ifndef Telebot_InlineQuery_H
#define Telebot_InlineQuery_H

#include <Telebot/Types/User.h>
#include <Telebot/Types/Location.h>

namespace Telebot
{
    class InlineQuery
    {
    public:
        typedef std::shared_ptr<InlineQuery> Ptr;

        std::string id;
        User::Ptr from;
        std::string query;
        std::string offset;
        std::string chat_type;
        Location::Ptr location;
    };

    inline void from_json(const ExtendedCpp::Json& json, InlineQuery& object) noexcept
    {
        VALUE_FROM_JSON(id)
        OBJECT_FROM_JSON(from)
        VALUE_FROM_JSON(query)
        VALUE_FROM_JSON(offset)
        VALUE_FROM_JSON(chat_type)
        OBJECT_FROM_JSON(location)
    }
}

#endif