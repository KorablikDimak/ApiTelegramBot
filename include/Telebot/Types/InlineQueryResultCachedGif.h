#ifndef Telebot_InlineQueryResultCachedGif_H
#define Telebot_InlineQueryResultCachedGif_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultCachedGif final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultCachedGif> Ptr;

        static const std::string TYPE;

        InlineQueryResultCachedGif()
        {
            Type = TYPE;
        }

        std::string GifFileId;
        std::string Title;
        std::string Caption;
        std::string ParseMode;
        std::vector<MessageEntity::Ptr> CaptionEntities;
        InputMessageContent::Ptr InputMessageContent;
    };
}

#endif