#ifndef Telebot_InlineQueryResultDocument_H
#define Telebot_InlineQueryResultDocument_H

#include <Telebot/Types/InlineQueryResult.h>
#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/InputMessageContent.h>

namespace Telebot
{
    class InlineQueryResultDocument final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultDocument> Ptr;

        static const std::string TYPE;

        InlineQueryResultDocument() noexcept
        {
            Type = TYPE;
        }

        std::string Title;
        std::string Caption;
        std::string ParseMode;
        std::vector<MessageEntity::Ptr> CaptionEntities;
        std::string DocumentUrl;
        std::string MimeType;
        std::string Description;
        InputMessageContent::Ptr InputMessageContent;
        std::string ThumbUrl;
        std::int32_t ThumbWidth{};
        std::int32_t ThumbHeight{};
    };
}

#endif