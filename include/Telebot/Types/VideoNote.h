#ifndef Telebot_VideoNote_H
#define Telebot_VideoNote_H

#include <Telebot/Types/PhotoSize.h>

namespace Telebot
{
    class VideoNote
    {
    public:
        typedef std::shared_ptr<VideoNote> Ptr;

        std::string file_id;
        std::string file_unique_id;
        std::int32_t length;
        std::int32_t duration;
        PhotoSize::Ptr thumb;
        std::int32_t file_size;
    };

    inline void from_json(const Json::Json& json, VideoNote& object) noexcept
    {
        VALUE_FROM_JSON(file_id)
        VALUE_FROM_JSON(file_unique_id)
        VALUE_FROM_JSON(length)
        VALUE_FROM_JSON(duration)
        OBJECT_FROM_JSON(thumb)
        VALUE_FROM_JSON(file_size)
    }
}

#endif
