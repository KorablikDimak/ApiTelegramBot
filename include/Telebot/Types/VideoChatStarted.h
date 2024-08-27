#ifndef Telebot_VideoChatStarted_H
#define Telebot_VideoChatStarted_H

#include <Json/Json.h>

namespace Telebot
{
    class VideoChatStarted
    {
    public:
        typedef std::shared_ptr<VideoChatStarted> Ptr;
    };

    inline void from_json(const Json::Json& json, VideoChatStarted& object) noexcept {}
}

#endif