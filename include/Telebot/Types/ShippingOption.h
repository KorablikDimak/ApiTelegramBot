#ifndef Telebot_ShippingOption_H
#define Telebot_ShippingOption_H

#include <vector>

#include <Telebot/Types/LabeledPrice.h>

namespace Telebot
{
    class ShippingOption
    {
    public:
        typedef std::shared_ptr<ShippingOption> Ptr;

        std::string Id;
        std::string Title;
        std::vector<LabeledPrice::Ptr> Prices;
    };
}

#endif