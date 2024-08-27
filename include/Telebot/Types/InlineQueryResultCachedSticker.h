#ifndef Telebot_InlineQueryResultCachedSticker_H
#define Telebot_InlineQueryResultCachedSticker_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultCachedSticker final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultCachedSticker> Ptr;

        static const std::string TYPE;

        InlineQueryResultCachedSticker() noexcept
        {
            Type = TYPE;
        }

        std::string StickerFileId;
        InputMessageContent::Ptr InputMessageContent;
    };
}

#endif