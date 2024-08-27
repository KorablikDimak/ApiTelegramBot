#ifndef Telebot_InlineQueryResultMpeg4Gif_H
#define Telebot_InlineQueryResultMpeg4Gif_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultMpeg4Gif final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultMpeg4Gif> Ptr;

        static const std::string TYPE;

        InlineQueryResultMpeg4Gif() noexcept
        {
            Type = TYPE;
        }

        std::string Mpeg4Url;
        std::int32_t Mpeg4Width{};
        std::int32_t Mpeg4Height{};
        std::int32_t Mpeg4Duration{};
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