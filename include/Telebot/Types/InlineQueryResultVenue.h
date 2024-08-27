#ifndef Telebot_InlineQueryResultVenue_H
#define Telebot_InlineQueryResultVenue_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultVenue final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultVenue> Ptr;

        static const std::string TYPE;

        InlineQueryResultVenue() noexcept
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
        InputMessageContent::Ptr InputMessageContent;
        std::string ThumbUrl;
        std::int32_t ThumbWidth{};
        std::int32_t ThumbHeight{};
    };
}

#endif