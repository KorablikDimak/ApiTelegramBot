#ifndef Telebot_PhotoSize_H
#define Telebot_PhotoSize_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class PhotoSize
    {
    public:
        typedef std::shared_ptr<PhotoSize> Ptr;

        std::string file_id;
        std::string file_unique_id;
        std::int32_t width;
        std::int32_t height;
        std::int32_t file_size;
    };

    inline void from_json(const ExtendedCpp::Json& json, PhotoSize& object) noexcept
    {
        VALUE_FROM_JSON(file_id)
        VALUE_FROM_JSON(file_unique_id)
        VALUE_FROM_JSON(width)
        VALUE_FROM_JSON(height)
        VALUE_FROM_JSON(file_size)
    }
}

#endif