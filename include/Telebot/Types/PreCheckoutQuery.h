#ifndef Telebot_PreCheckoutQuery_H
#define Telebot_PreCheckoutQuery_H

#include <Telebot/Types/User.h>
#include <Telebot/Types/OrderInfo.h>

namespace Telebot
{
    class PreCheckoutQuery
    {
    public:
        typedef std::shared_ptr<PreCheckoutQuery> Ptr;

        std::string id;
        User::Ptr from;
        std::string currency;
        std::int32_t total_amount;
        std::string invoice_payload;
        std::string shipping_option_id;
        OrderInfo::Ptr order_info;
    };

    inline void from_json(const ExtendedCpp::Json& json, PreCheckoutQuery& object) noexcept
    {
        VALUE_FROM_JSON(id)
        OBJECT_FROM_JSON(from)
        VALUE_FROM_JSON(currency)
        VALUE_FROM_JSON(total_amount)
        VALUE_FROM_JSON(invoice_payload)
        VALUE_FROM_JSON(shipping_option_id)
        OBJECT_FROM_JSON(order_info)
    }
}

#endif