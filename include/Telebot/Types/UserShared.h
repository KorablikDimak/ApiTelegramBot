#ifndef Telebot_UserShared_H
#define Telebot_UserShared_H

#include <Json/Json.h>

namespace Telebot
{
    class UserShared
    {
    public:
        typedef std::shared_ptr<UserShared> Ptr;

        std::int32_t request_id;
        std::int64_t user_id;
    };

    inline void from_json(const Json::Json& json, UserShared& object)
    {
        VALUE_FROM_JSON(request_id)
        VALUE_FROM_JSON(user_id)
    }
}

#endif