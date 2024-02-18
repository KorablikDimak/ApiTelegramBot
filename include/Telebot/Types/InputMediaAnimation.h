#ifndef Telebot_InputMediaAnimation_H
#define Telebot_InputMediaAnimation_H

#include <Telebot/Types/InputMedia.h>

namespace Telebot
{
    class InputMediaAnimation final : public InputMedia
    {
    public:
        typedef std::shared_ptr<InputMediaAnimation> Ptr;

        static const std::string TYPE;

        InputMediaAnimation()
        {
            Type = TYPE;
        }

        std::string Thumb;
        std::int32_t Width;
        std::int32_t Height;
        std::int32_t Duration;
        bool HasSpoiler;
    };
}

#endif