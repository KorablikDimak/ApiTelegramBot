#ifndef Telebot_InlineQueryResultCachedVoice_H
#define Telebot_InlineQueryResultCachedVoice_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultCachedVoice final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultCachedVoice> Ptr;

        static const std::string TYPE;

        InlineQueryResultCachedVoice() noexcept
        {
            Type = TYPE;
        }

        std::string VoiceFileId;
        std::string Title;
        std::string Caption;
        std::string ParseMode;
        std::vector<MessageEntity::Ptr> CaptionEntities;
        InputMessageContent::Ptr InputMessageContent;
    };
}

#endif