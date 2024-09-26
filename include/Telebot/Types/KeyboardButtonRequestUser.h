#ifndef Telebot_KeyboardButtonRequestUser_H
#define Telebot_KeyboardButtonRequestUser_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class KeyboardButtonRequestUser
    {
    public:
        typedef std::shared_ptr<KeyboardButtonRequestUser> Ptr;

        std::int32_t request_id;
        bool user_is_bot;
        bool user_is_premium;
    };

    inline void to_json(ExtendedCpp::Json& json, const KeyboardButtonRequestUser::Ptr& object) noexcept
    {
        VALUE_TO_JSON(request_id)
        VALUE_TO_JSON(user_is_bot)
        VALUE_TO_JSON(user_is_premium)
    }
}

#endif