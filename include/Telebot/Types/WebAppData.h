#ifndef Telebot_WebAppData_H
#define Telebot_WebAppData_H

#include <Json/Json.h>

namespace Telebot
{
    class WebAppData
    {
    public:
        typedef std::shared_ptr<WebAppData> Ptr;

        std::string data;
        std::string button_text;
    };

    inline void from_json(const Json::Json& json, WebAppData& object)
    {
        VALUE_FROM_JSON(data)
        VALUE_FROM_JSON(button_text)
    }
}

#endif