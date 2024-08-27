#ifndef Telebot_InputVenueMessageContent_H
#define Telebot_InputVenueMessageContent_H

#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InputVenueMessageContent final : public InputMessageContent
    {
    public:
        typedef std::shared_ptr<InputVenueMessageContent> Ptr;

        static const std::string TYPE;

        InputVenueMessageContent() noexcept
        {
            Type = TYPE;
        }

        float Latitude{};
        float Longitude{};
        std::string Title;
        std::string Address;
        std::string FoursquareId;
        std::string FoursquareType;
        std::string GooglePlaceId;
        std::string GooglePlaceType;
    };
}

#endif