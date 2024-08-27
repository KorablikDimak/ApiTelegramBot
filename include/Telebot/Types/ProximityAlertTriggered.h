#ifndef Telebot_ProximityAlertTriggered_H
#define Telebot_ProximityAlertTriggered_H

#include <Telebot/Types/User.h>

namespace Telebot
{
    class ProximityAlertTriggered
    {
    public:
        typedef std::shared_ptr<ProximityAlertTriggered> Ptr;

        User::Ptr traveler;
        User::Ptr watcher;
        std::int32_t distance;
    };

    inline void from_json(const Json::Json& json, ProximityAlertTriggered& object) noexcept
    {
        OBJECT_FROM_JSON(traveler)
        OBJECT_FROM_JSON(watcher)
        VALUE_FROM_JSON(distance)
    }
}

#endif