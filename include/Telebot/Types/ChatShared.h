#ifndef Telebot_ChatShared_H
#define Telebot_ChatShared_H

#include <Json/Json.h>

namespace Telebot
{
    class ChatShared
    {
    public:
        typedef std::shared_ptr<ChatShared> Ptr;

        std::int32_t request_id;
        std::int64_t user_id;
    };

    inline void from_json(const Json::Json& json, ChatShared& object)
    {
        VALUE_FROM_JSON(request_id)
        VALUE_FROM_JSON(user_id)
    }
}

#endif