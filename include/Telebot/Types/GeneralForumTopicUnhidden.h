#ifndef Telebot_GeneralForumTopicUnhidden_H
#define Telebot_GeneralForumTopicUnhidden_H

#include <Json/Json.h>

namespace Telebot
{
    class GeneralForumTopicUnhidden
    {
    public:
        typedef std::shared_ptr<GeneralForumTopicUnhidden> Ptr;
    };

    inline void from_json(const Json::Json& json, GeneralForumTopicUnhidden& object) {}
}

#endif