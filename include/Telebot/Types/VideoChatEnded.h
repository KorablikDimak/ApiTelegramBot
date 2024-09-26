#ifndef Telebot_VideoChatEnded_H
#define Telebot_VideoChatEnded_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class VideoChatEnded
    {
    public:
        typedef std::shared_ptr<VideoChatEnded> Ptr;

        std::int32_t duration;
    };

    inline void from_json(const ExtendedCpp::Json& json, VideoChatEnded& object) noexcept
    {
        VALUE_FROM_JSON(duration)
    }
}

#endif