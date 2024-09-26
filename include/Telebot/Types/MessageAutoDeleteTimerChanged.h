#ifndef Telebot_MessageAutoDeleteTimerChanged_H
#define Telebot_MessageAutoDeleteTimerChanged_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class MessageAutoDeleteTimerChanged
    {
    public:
        typedef std::shared_ptr<MessageAutoDeleteTimerChanged> Ptr;

        std::int32_t message_auto_delete_time;
    };

    inline void from_json(const ExtendedCpp::Json& json, MessageAutoDeleteTimerChanged& object) noexcept
    {
        VALUE_FROM_JSON(message_auto_delete_time)
    }
}

#endif