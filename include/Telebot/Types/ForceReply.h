#ifndef Telebot_ForceReply_H
#define Telebot_ForceReply_H

#include <Telebot/Types/GenericReply.h>

namespace Telebot
{
    class ForceReply final : public GenericReply
    {
    public:
        typedef std::shared_ptr<ForceReply> Ptr;

        ~ForceReply() override = default;

        bool force_reply;
        std::string input_field_placeholder;
        bool selective;

        void ToJson(ExtendedCpp::Json& json, const GenericReply::Ptr& object) noexcept override;
    };

    inline void to_json(ExtendedCpp::Json& json, const ForceReply::Ptr& object) noexcept
    {
        VALUE_TO_JSON(force_reply)
        if (!object->input_field_placeholder.empty()) VALUE_TO_JSON(input_field_placeholder)
        VALUE_TO_JSON(selective)
    }
}

#endif