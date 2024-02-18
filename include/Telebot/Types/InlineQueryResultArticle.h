#ifndef Telebot_InlineQueryResultArticle_H
#define Telebot_InlineQueryResultArticle_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultArticle final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultArticle> Ptr;

        static const std::string TYPE;

        InlineQueryResultArticle()
        {
            Type = TYPE;
        }

        std::string Title;
        InputMessageContent::Ptr InputMessageContent;
        std::string Url;
        bool HideUrl;
        std::string Description;
        std::string ThumbUrl;
        std::int32_t ThumbWidth;
        std::int32_t ThumbHeight;
    };
}

#endif