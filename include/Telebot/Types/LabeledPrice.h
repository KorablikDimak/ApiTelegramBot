#ifndef Telebot_LabeledPrice_H
#define Telebot_LabeledPrice_H

#include <string>
#include <memory>

namespace Telebot
{
    class LabeledPrice
    {
    public:
        typedef std::shared_ptr<LabeledPrice> Ptr;

        std::string Label;
        std::int32_t Amount;
    };
}

#endif