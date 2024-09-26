#ifndef Telebot_WebAppInfo_H
#define Telebot_WebAppInfo_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class WebAppInfo
    {
    public:
        typedef std::shared_ptr<WebAppInfo> Ptr;

        std::string url;
    };

    inline void from_json(const ExtendedCpp::Json& json, WebAppInfo& object) noexcept
    {
        VALUE_FROM_JSON(url)
    }

    inline void to_json(ExtendedCpp::Json& json, const WebAppInfo::Ptr& object) noexcept
    {
        VALUE_TO_JSON(url)
    }
}

#endif