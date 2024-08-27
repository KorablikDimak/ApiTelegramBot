#ifndef Telebot_VideoChatScheduled_H
#define Telebot_VideoChatScheduled_H

#include <Json/Json.h>

namespace Telebot
{
    class VideoChatScheduled
    {
    public:
        typedef std::shared_ptr<VideoChatScheduled> Ptr;

        std::int32_t start_date;
    };

    inline void from_json(const Json::Json& json, VideoChatScheduled& object) noexcept
    {
        VALUE_FROM_JSON(start_date)
    }
}

#endif