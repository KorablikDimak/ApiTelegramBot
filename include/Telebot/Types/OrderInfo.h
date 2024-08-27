#ifndef Telebot_OrderInfo_H
#define Telebot_OrderInfo_H

#include <Telebot/Types/ShippingAddress.h>

namespace Telebot
{
    class OrderInfo
    {
    public:
        typedef std::shared_ptr<OrderInfo> Ptr;

        std::string name;
        std::string phone_number;
        std::string email;
        ShippingAddress::Ptr shipping_address;
    };

    inline void from_json(const Json::Json& json, OrderInfo& object) noexcept
    {
        VALUE_FROM_JSON(name)
        VALUE_FROM_JSON(phone_number)
        VALUE_FROM_JSON(email)
        OBJECT_FROM_JSON(shipping_address)
    }
}

#endif