#ifndef Telebot_InputMedia_H
#define Telebot_InputMedia_H

#include <vector>

#include <Telebot/Types/MessageEntity.h>

namespace Telebot
{
    class InputMedia
    {
    public:
        typedef std::shared_ptr<InputMedia> Ptr;

        InputMedia() noexcept = default;
        virtual ~InputMedia() = default;

        std::string Type;
        std::string Media;
        std::string Caption;
        std::string ParseMode;
        std::vector<MessageEntity::Ptr> CaptionEntities;
    };
}

#endif