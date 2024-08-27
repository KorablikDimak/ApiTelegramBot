#ifndef Telebot_InputMediaAudio_H
#define Telebot_InputMediaAudio_H

#include <Telebot/Types/InputMedia.h>

namespace Telebot
{
    class InputMediaAudio final : public InputMedia
    {
    public:
        typedef std::shared_ptr<InputMediaAudio> Ptr;

        static const std::string TYPE;

        InputMediaAudio() noexcept
        {
            Type = TYPE;
        }

        std::string Thumb;
        std::int32_t Duration{};
        std::string Performer;
        std::string Title;
    };
}

#endif