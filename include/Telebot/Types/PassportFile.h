#ifndef Telebot_PassportFile_H
#define Telebot_PassportFile_H

#include <Json/Json.h>

namespace Telebot
{
    class PassportFile
    {
    public:
        typedef std::shared_ptr<PassportFile> Ptr;

        std::string file_id;
        std::string file_unique_id;
        std::int32_t file_size;
        std::int32_t file_date;
    };

    inline void from_json(const Json::Json& json, PassportFile& object)
    {
        VALUE_FROM_JSON(file_id)
        VALUE_FROM_JSON(file_unique_id)
        VALUE_FROM_JSON(file_size)
        VALUE_FROM_JSON(file_date)
    }
}

#endif