#ifndef Telebot_InputMediaPhoto_H
#define Telebot_InputMediaPhoto_H

#include <Telebot/Types/InputMedia.h>

namespace Telebot
{
    class InputMediaPhoto final : public InputMedia
    {
    public:
        typedef std::shared_ptr<InputMediaPhoto> Ptr;

        static const std::string TYPE;

        InputMediaPhoto()
        {
            Type = TYPE;
        }

        bool HasSpoiler;
    };
}

#endif