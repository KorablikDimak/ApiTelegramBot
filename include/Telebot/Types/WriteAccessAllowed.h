#ifndef Telebot_WriteAccessAllowed_H
#define Telebot_WriteAccessAllowed_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class WriteAccessAllowed
    {
    public:
        typedef std::shared_ptr<WriteAccessAllowed> Ptr;
    };

    inline void from_json(const ExtendedCpp::Json& json, WriteAccessAllowed& object) noexcept {}
}

#endif