#ifndef Telebot_InlineQueryResultVideo_H
#define Telebot_InlineQueryResultVideo_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultVideo final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultVideo> Ptr;

        static const std::string TYPE;

        InlineQueryResultVideo() noexcept
        {
            Type = TYPE;
        };

        std::string VideoUrl;
        std::string MimeType;
        std::string ThumbUrl;
        std::string Title;
        std::string Caption;
        std::string ParseMode;
        std::vector<MessageEntity::Ptr> CaptionEntities;
        std::int32_t VideoWidth{};
        std::int32_t VideoHeight{};
        std::int32_t VideoDuration{};
        std::string Description;
        InputMessageContent::Ptr InputMessageContent;
    };
}

#endif