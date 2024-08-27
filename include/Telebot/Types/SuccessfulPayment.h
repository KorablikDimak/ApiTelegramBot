#ifndef Telebot_SuccessfulPayment_H
#define Telebot_SuccessfulPayment_H

#include <Telebot/Types/OrderInfo.h>

namespace Telebot
{
    class SuccessfulPayment
    {
    public:
        typedef std::shared_ptr<SuccessfulPayment> Ptr;

        std::string currency;
        std::int32_t total_amount;
        std::string invoice_payload;
        std::string shipping_optionId;
        OrderInfo::Ptr order_info;
        std::string telegram_payment_charge_id;
        std::string provider_payment_charge_id;
    };

    inline void from_json(const Json::Json& json, SuccessfulPayment& object) noexcept
    {
        VALUE_FROM_JSON(currency)
        VALUE_FROM_JSON(total_amount)
        VALUE_FROM_JSON(invoice_payload)
        VALUE_FROM_JSON(shipping_optionId)
        OBJECT_FROM_JSON(order_info)
        VALUE_FROM_JSON(telegram_payment_charge_id)
        VALUE_FROM_JSON(provider_payment_charge_id)
    }
}

#endif