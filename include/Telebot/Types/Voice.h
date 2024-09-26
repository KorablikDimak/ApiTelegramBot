#ifndef Telebot_Voice_H
#define Telebot_Voice_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class Voice
    {
    public:
        typedef std::shared_ptr<Voice> Ptr;

        std::string file_id;
        std::string file_unique_id;
        std::int32_t duration;
        std::string mime_type;
        std::int64_t file_size;
    };

    inline void from_json(const ExtendedCpp::Json& json, Voice& object) noexcept
    {
        VALUE_FROM_JSON(file_id)
        VALUE_FROM_JSON(file_unique_id)
        VALUE_FROM_JSON(duration)
        VALUE_FROM_JSON(mime_type)
        VALUE_FROM_JSON(file_size)
    }
}

#endif