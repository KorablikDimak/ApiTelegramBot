#ifndef Telebot_GenericReply_H
#define Telebot_GenericReply_H

#include <Json/Json.h>

namespace Telebot
{
    class GenericReply
    {
    public:
        typedef std::shared_ptr<GenericReply> Ptr;

        virtual ~GenericReply() = default;

        virtual void ToJson(Json::Json& json, const GenericReply::Ptr& object) noexcept;
    };

    inline void to_json(Json::Json& json, const GenericReply::Ptr& object) noexcept
    {
        object->ToJson(json, object);
    }
}

#endif