#ifndef Telebot_ForumTopic_H
#define Telebot_ForumTopic_H

#include <string>
#include <memory>

namespace Telebot
{
    class ForumTopic
    {
    public:
        typedef std::shared_ptr<ForumTopic> Ptr;

        std::int32_t MessageThreadId;
        std::string Name;
        std::int32_t IconColor;
        std::string IconCustomEmojiId;
    };
}

#endif