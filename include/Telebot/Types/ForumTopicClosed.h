#ifndef Telebot_ForumTopicClosed_H
#define Telebot_ForumTopicClosed_H

#include <Json/Json.h>

namespace Telebot
{
    class ForumTopicClosed
    {
    public:
        typedef std::shared_ptr<ForumTopicClosed> Ptr;
    };

    inline void from_json(const Json::Json& json, ForumTopicClosed& object) {}
}

#endif