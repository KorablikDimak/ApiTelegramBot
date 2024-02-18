#ifndef Telebot_File_H
#define Telebot_File_H

#include <Json/Json.h>

namespace Telebot
{
    class File
    {
    public:
        typedef std::shared_ptr<File> Ptr;

        std::string file_id;
        std::string file_unique_id;
        std::int64_t file_size;
        std::string file_path;
    };

    inline void from_json(const Json::Json& json, File& object)
    {
        VALUE_FROM_JSON(file_id)
        VALUE_FROM_JSON(file_unique_id)
        VALUE_FROM_JSON(file_size)
        VALUE_FROM_JSON(file_path)
    }
}

#endif