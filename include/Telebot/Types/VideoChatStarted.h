#ifndef Telebot_VideoChatStarted_H
#define Telebot_VideoChatStarted_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class VideoChatStarted
    {
    public:
        typedef std::shared_ptr<VideoChatStarted> Ptr;
    };

    inline void from_json(const ExtendedCpp::Json& json, VideoChatStarted& object) noexcept {}
}

#endif