#ifndef Telebot_InlineQueryResultVoice_H
#define Telebot_InlineQueryResultVoice_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultVoice final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultVoice> Ptr;

        static const std::string TYPE;

        InlineQueryResultVoice() noexcept
        {
            Type = TYPE;
        };

        std::string VoiceUrl;
        std::string Title;
        std::string Caption;
        std::string parseMode;
        std::vector<MessageEntity::Ptr> CaptionEntities;
        std::int32_t VoiceDuration{};
        InputMessageContent::Ptr InputMessageContent;
    };
}

#endif