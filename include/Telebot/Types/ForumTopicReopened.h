#ifndef Telebot_ForumTopicReopened_H
#define Telebot_ForumTopicReopened_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class ForumTopicReopened
    {
    public:
        typedef std::shared_ptr<ForumTopicReopened> Ptr;
    };

    inline void from_json(const ExtendedCpp::Json& json, ForumTopicReopened& object) noexcept {}
}

#endif