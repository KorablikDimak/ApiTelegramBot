#ifndef Telebot_Location_H
#define Telebot_Location_H

#include <Json/Json.h>

namespace Telebot
{
    class Location
    {
    public:
        typedef std::shared_ptr<Location> Ptr;

        float longitude;
        float latitude;
        float horizontal_accuracy;
        std::int32_t live_period;
        std::int32_t heading;
        std::int32_t proximity_alert_radius;
    };

    inline void from_json(const Json::Json& json, Location& object)
    {
        VALUE_FROM_JSON(longitude)
        VALUE_FROM_JSON(latitude)
        VALUE_FROM_JSON(horizontal_accuracy)
        VALUE_FROM_JSON(live_period)
        VALUE_FROM_JSON(heading)
        VALUE_FROM_JSON(proximity_alert_radius)
    }
}

#endif