#ifndef Telebot_ForumTopicCreated_H
#define Telebot_ForumTopicCreated_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class ForumTopicCreated
    {
    public:
        typedef std::shared_ptr<ForumTopicCreated> Ptr;

        std::string name;
        std::int32_t icon_color;
        std::string icon_custom_emoji_id;
    };

    inline void from_json(const ExtendedCpp::Json& json, ForumTopicCreated& object) noexcept
    {
        VALUE_FROM_JSON(name)
        VALUE_FROM_JSON(icon_color)
        VALUE_FROM_JSON(icon_custom_emoji_id)
    }
}

#endif