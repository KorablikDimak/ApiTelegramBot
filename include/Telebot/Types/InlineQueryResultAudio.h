#ifndef Telebot_InlineQueryResultAudio_H
#define Telebot_InlineQueryResultAudio_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultAudio final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultAudio> Ptr;

        static const std::string TYPE;

        InlineQueryResultAudio() noexcept
        {
            Type = TYPE;
        }

        std::string AudioUrl;
        std::string Title;
        std::string Caption;
        std::string ParseMode;
        std::vector<MessageEntity::Ptr> CaptionEntities;
        std::string Performer;
        std::int32_t AudioDuration{};
        InputMessageContent::Ptr InputMessageContent;
    };
}

#endif