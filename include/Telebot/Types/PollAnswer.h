#ifndef Telebot_PollAnswer_H
#define Telebot_PollAnswer_H

#include <Telebot/Types/User.h>

namespace Telebot
{
    class PollAnswer
    {
    public:
        typedef std::shared_ptr<PollAnswer> Ptr;

        std::string poll_id;
        User::Ptr user;
        std::vector<std::int32_t> option_ids;
    };

    inline void from_json(const ExtendedCpp::Json& json, PollAnswer& object) noexcept
    {
        VALUE_FROM_JSON(poll_id)
        OBJECT_FROM_JSON(user)
        VALUES_FROM_JSON(option_ids)
    }
}

#endif