#ifndef Telebot_PollOption_H
#define Telebot_PollOption_H

#include <Json/Json.h>

namespace Telebot
{
    class PollOption
    {
    public:
        typedef std::shared_ptr<PollOption> Ptr;

        std::string text;
        std::int64_t voter_count;
    };

    inline void from_json(const Json::Json& json, PollOption& object) noexcept
    {
        VALUE_FROM_JSON(text)
        VALUE_FROM_JSON(voter_count)
    }
}

#endif