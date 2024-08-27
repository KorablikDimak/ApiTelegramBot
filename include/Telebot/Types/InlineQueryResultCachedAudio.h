#ifndef Telebot_InlineQueryResultCachedAudio_H
#define Telebot_InlineQueryResultCachedAudio_H

#include <vector>

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultCachedAudio final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultCachedAudio> Ptr;

        static const std::string TYPE;

        InlineQueryResultCachedAudio() noexcept
        {
            Type = TYPE;
        }

        std::string AudioFileId;
        std::string Caption;
        std::string ParseMode;
        std::vector<MessageEntity::Ptr> CaptionEntities;
        InputMessageContent::Ptr InputMessageContent;
    };
}

#endif