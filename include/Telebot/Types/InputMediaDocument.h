#ifndef Telebot_InputMediaDocument_H
#define Telebot_InputMediaDocument_H

#include <Telebot/Types/InputMedia.h>

namespace Telebot
{
    class InputMediaDocument final : public InputMedia
    {
    public:
        typedef std::shared_ptr<InputMediaDocument> Ptr;

        static const std::string TYPE;

        InputMediaDocument()
        {
            Type = TYPE;
        }

        std::string Thumb;
        bool DisableContentTypeDetection;
    };
}

#endif