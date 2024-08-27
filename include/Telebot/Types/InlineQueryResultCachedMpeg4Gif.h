#ifndef Telebot_InlineQueryResultCachedMpeg4Gif_H
#define Telebot_InlineQueryResultCachedMpeg4Gif_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultCachedMpeg4Gif final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultCachedMpeg4Gif> Ptr;

        static const std::string TYPE;

        InlineQueryResultCachedMpeg4Gif() noexcept
        {
            Type = TYPE;
        }

        std::string Mpeg4FileId;
        std::string Title;
        std::string Caption;
        std::string ParseMode;
        std::vector<MessageEntity::Ptr> CaptionEntities;
        InputMessageContent::Ptr InputMessageContent;
    };
}

#endif