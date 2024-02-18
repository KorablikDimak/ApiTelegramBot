#ifndef Telebot_InlineQueryResultCachedVideo_H
#define Telebot_InlineQueryResultCachedVideo_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultCachedVideo final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultCachedVideo> Ptr;

        static const std::string TYPE;

        InlineQueryResultCachedVideo()
        {
            Type = TYPE;
        }

        std::string VideoFileId;
        std::string Title;
        std::string Description;
        std::string Caption;
        std::string ParseMode;
        std::vector<MessageEntity::Ptr> CaptionEntities;
        InputMessageContent::Ptr InputMessageContent;
    };
}

#endif