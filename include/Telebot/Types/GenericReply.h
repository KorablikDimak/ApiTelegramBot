#ifndef Telebot_GenericReply_H
#define Telebot_GenericReply_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class GenericReply
    {
    public:
        typedef std::shared_ptr<GenericReply> Ptr;

        virtual ~GenericReply() = default;

        virtual void ToJson(ExtendedCpp::Json& json, const GenericReply::Ptr& object) noexcept;
    };

    inline void to_json(ExtendedCpp::Json& json, const GenericReply::Ptr& object) noexcept
    {
        object->ToJson(json, object);
    }
}

#endif