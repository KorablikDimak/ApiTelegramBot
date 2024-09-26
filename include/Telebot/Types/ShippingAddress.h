#ifndef Telebot_ShippingAddress_H
#define Telebot_ShippingAddress_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class ShippingAddress
    {
    public:
        typedef std::shared_ptr<ShippingAddress> Ptr;

        std::string country_code;
        std::string state;
        std::string city;
        std::string street_line1;
        std::string street_line2;
        std::string post_code;
    };

    inline void from_json(const ExtendedCpp::Json& json, ShippingAddress& object) noexcept
    {
        VALUE_FROM_JSON(country_code)
        VALUE_FROM_JSON(state)
        VALUE_FROM_JSON(city)
        VALUE_FROM_JSON(street_line1)
        VALUE_FROM_JSON(street_line2)
        VALUE_FROM_JSON(post_code)
    }
}

#endif