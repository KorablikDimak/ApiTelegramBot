#ifndef Telebot_ChatPhoto_H
#define Telebot_ChatPhoto_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class ChatPhoto
    {
    public:
        typedef std::shared_ptr<ChatPhoto> Ptr;

        std::string small_file_id;
        std::string small_file_unique_id;
        std::string big_file_id;
        std::string big_file_unique_id;
    };

    inline void from_json(const ExtendedCpp::Json& json, ChatPhoto& object) noexcept
    {
        VALUE_FROM_JSON(small_file_id)
        VALUE_FROM_JSON(small_file_unique_id)
        VALUE_FROM_JSON(big_file_id)
        VALUE_FROM_JSON(big_file_unique_id)
    }
}

#endif