#ifndef Telebot_InputMediaVideo_H
#define Telebot_InputMediaVideo_H

#include <Telebot/Types/InputMedia.h>
#include <Telebot/Types/InputFile.h>

namespace Telebot
{
    class InputMediaVideo final : public InputMedia
    {
    public:
        typedef std::shared_ptr<InputMediaVideo> Ptr;

        static const std::string TYPE;

        InputMediaVideo() noexcept
        {
            Type = TYPE;
        }

        std::string Thumb;
        std::int32_t Width{};
        std::int32_t Height{};
        std::int32_t Duration{};
        bool SupportsStreaming{};
        bool HasSpoiler{};
    };
}

#endif