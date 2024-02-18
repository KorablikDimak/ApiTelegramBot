#ifndef Telebot_InlineQueryResultGif_H
#define Telebot_InlineQueryResultGif_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultGif final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultGif> Ptr;

        static const std::string TYPE;

        InlineQueryResultGif()
        {
            Type = TYPE;
        }

        std::string GifUrl;
        std::int32_t GifWidth;
        std::int32_t GifHeight;
        std::int32_t GifDuration;
        std::string ThumbUrl;
        std::string ThumbMimeType;
        std::string Title;
        std::string Caption;
        std::string ParseMode;
        std::vector<MessageEntity::Ptr> CaptionEntities;
        InputMessageContent::Ptr InputMessageContent;
    };
}

#endif