#ifndef Telebot_InlineQueryResultCachedPhoto_H
#define Telebot_InlineQueryResultCachedPhoto_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultCachedPhoto final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultCachedPhoto> Ptr;

        static const std::string TYPE;

        InlineQueryResultCachedPhoto() noexcept
        {
            Type = TYPE;
        }

        std::string PhotoFileId;
        std::string Title;
        std::string Description;
        std::string Caption;
        std::string ParseMode;
        std::vector<MessageEntity::Ptr> CaptionEntities;
        InputMessageContent::Ptr InputMessageContent;
    };
}

#endif