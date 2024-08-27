#ifndef Telebot_InlineQueryResultCachedDocument_H
#define Telebot_InlineQueryResultCachedDocument_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultCachedDocument final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultCachedDocument> Ptr;

        static const std::string TYPE;

        InlineQueryResultCachedDocument() noexcept
        {
            Type = TYPE;
        }

        std::string Title;
        std::string DocumentFileId;
        std::string Description;
        std::string Caption;
        std::string ParseMode;
        std::vector<MessageEntity::Ptr> CaptionEntities;
        InputMessageContent::Ptr InputMessageContent;
    };
}

#endif