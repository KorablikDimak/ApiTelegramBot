#ifndef Telebot_Venue_H
#define Telebot_Venue_H

#include <Telebot/Types/Location.h>

namespace Telebot
{
    class Venue
    {
    public:
        typedef std::shared_ptr<Venue> Ptr;

        Location::Ptr location;
        std::string title;
        std::string address;
        std::string foursquare_id;
        std::string foursquare_type;
        std::string google_place_id;
        std::string google_place_type;
    };

    inline void from_json(const Json::Json& json, Venue& object) noexcept
    {
        OBJECT_FROM_JSON(location)
        VALUE_FROM_JSON(title)
        VALUE_FROM_JSON(address)
        VALUE_FROM_JSON(foursquare_id)
        VALUE_FROM_JSON(foursquare_type)
        VALUE_FROM_JSON(google_place_id)
        VALUE_FROM_JSON(google_place_type)
    }
}

#endif