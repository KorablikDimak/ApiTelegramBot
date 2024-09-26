#ifndef Telebot_GeneralForumTopicUnhidden_H
#define Telebot_GeneralForumTopicUnhidden_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class GeneralForumTopicUnhidden
    {
    public:
        typedef std::shared_ptr<GeneralForumTopicUnhidden> Ptr;
    };

    inline void from_json(const ExtendedCpp::Json& json, GeneralForumTopicUnhidden& object) noexcept {}
}

#endif