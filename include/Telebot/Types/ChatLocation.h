#ifndef Telebot_ChatLocation_H
#define Telebot_ChatLocation_H

#include <Telebot/Types/Location.h>

namespace Telebot
{
    class ChatLocation
    {
    public:
        typedef std::shared_ptr<ChatLocation> Ptr;

        Location::Ptr location;
        std::string address;
    };

    inline void from_json(const Json::Json& json, ChatLocation& object)
    {
        OBJECT_FROM_JSON(location)
        VALUE_FROM_JSON(address)
    }
}

#endif