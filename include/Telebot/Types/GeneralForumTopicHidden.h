#ifndef Telebot_GeneralForumTopicHidden_H
#define Telebot_GeneralForumTopicHidden_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class GeneralForumTopicHidden
    {
    public:
        typedef std::shared_ptr<GeneralForumTopicHidden> Ptr;
    };

    inline void from_json(const ExtendedCpp::Json& json, GeneralForumTopicHidden& object) noexcept {}
}

#endif