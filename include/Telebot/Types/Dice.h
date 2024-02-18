#ifndef Telebot_Dice_H
#define Telebot_Dice_H

#include <Json/Json.h>

namespace Telebot
{
    class Dice
    {
    public:
        typedef std::shared_ptr<Dice> Ptr;

        std::string emoji;
        std::int32_t value;
    };

    inline void from_json(const Json::Json& json, Dice& object)
    {
        VALUE_FROM_JSON(emoji)
        VALUE_FROM_JSON(value)
    }
}

#endif