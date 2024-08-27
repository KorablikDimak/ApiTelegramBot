#ifndef Telebot_CallbackGame_H
#define Telebot_CallbackGame_H

#include <Json/Json.h>

namespace Telebot
{
    class CallbackGame
    {
    public:
        typedef std::shared_ptr<CallbackGame> Ptr;
    };

    inline void from_json(const Json::Json& json, CallbackGame& object) noexcept {}
    inline void to_json(Json::Json& json, const CallbackGame::Ptr& object) noexcept {}
}

#endif