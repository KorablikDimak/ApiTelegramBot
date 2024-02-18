#ifndef Telebot_ReplyKeyboardRemove_H
#define Telebot_ReplyKeyboardRemove_H

#include <Telebot/Types/GenericReply.h>

namespace Telebot
{
    class ReplyKeyboardRemove final : public GenericReply
    {
    public:
        typedef std::shared_ptr<ReplyKeyboardRemove> Ptr;

        ~ReplyKeyboardRemove() override = default;

        bool remove_keyboard;
        bool selective;

        void ToJson(Json::Json& json, const GenericReply::Ptr& object) override;
    };

    inline void to_json(Json::Json& json, const ReplyKeyboardRemove::Ptr& object)
    {
        VALUE_TO_JSON(remove_keyboard)
        VALUE_TO_JSON(selective)
    }
}

#endif