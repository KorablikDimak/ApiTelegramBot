#ifndef Telebot_ShippingQuery_H
#define Telebot_ShippingQuery_H

#include <Telebot/Types/User.h>
#include <Telebot/Types/ShippingAddress.h>

namespace Telebot
{
    class ShippingQuery
    {
    public:
        typedef std::shared_ptr<ShippingQuery> Ptr;

        std::string id;
        User::Ptr from;
        std::string invoice_payload;
        ShippingAddress::Ptr shipping_address;
    };

    inline void from_json(const ExtendedCpp::Json& json, ShippingQuery& object) noexcept
    {
        VALUE_FROM_JSON(id)
        OBJECT_FROM_JSON(from)
        VALUE_FROM_JSON(invoice_payload)
        OBJECT_FROM_JSON(shipping_address)
    }
}

#endif