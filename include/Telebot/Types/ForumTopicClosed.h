#ifndef Telebot_ForumTopicClosed_H
#define Telebot_ForumTopicClosed_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class ForumTopicClosed
    {
    public:
        typedef std::shared_ptr<ForumTopicClosed> Ptr;
    };

    inline void from_json(const ExtendedCpp::Json& json, ForumTopicClosed& object) noexcept {}
}

#endif