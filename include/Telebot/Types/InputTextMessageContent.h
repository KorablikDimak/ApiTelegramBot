#ifndef Telebot_InputTextMessageContent_H
#define Telebot_InputTextMessageContent_H

#include <vector>

#include <Telebot/Types/InputMessageContent.h>
#include <Telebot/Types/MessageEntity.h>

namespace Telebot
{
    class InputTextMessageContent final : public InputMessageContent
    {
    public:
        typedef std::shared_ptr<InputTextMessageContent> Ptr;

        static const std::string TYPE;

        InputTextMessageContent() noexcept
        {
            Type = TYPE;
        }

        std::string MessageText;
        std::string ParseMode;
        std::vector<MessageEntity::Ptr> Entities;
        bool DisableWebPagePreview{};
    };
}

#endif