#ifndef Telebot_InputLocationMessageContent_H
#define Telebot_InputLocationMessageContent_H

#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InputLocationMessageContent final : public InputMessageContent
    {
    public:
        typedef std::shared_ptr<InputLocationMessageContent> Ptr;

        static const std::string TYPE;

        InputLocationMessageContent() noexcept
        {
            Type = TYPE;
        }

        float Latitude{};
        float Longitude{};
        float HorizontalAccuracy{};
        std::int32_t LivePeriod{};
        std::int32_t Heading{};
        std::int32_t ProximityAlertRadius{};
    };
}

#endif