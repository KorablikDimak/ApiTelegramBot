#ifndef Telebot_InlineQueryResultContact_H
#define Telebot_InlineQueryResultContact_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultContact final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultContact> Ptr;

        static const std::string TYPE;

        InlineQueryResultContact()
        {
            Type = TYPE;
        }

        std::string PhoneNumber;
        std::string FirstName;
        std::string LastName;
        std::string Vcard;
        InputMessageContent::Ptr InputMessageContent;
        std::string ThumbUrl;
        std::int32_t ThumbWidth;
        std::int32_t ThumbHeight;
    };
}

#endif