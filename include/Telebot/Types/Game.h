#ifndef Telebot_Game_H
#define Telebot_Game_H

#include <Telebot/Types/MessageEntity.h>
#include <Telebot/Types/Animation.h>
#include <Telebot/Types/PhotoSize.h>

namespace Telebot
{
    class Game
    {
    public:
        typedef std::shared_ptr<Game> Ptr;

        std::string title;
        std::string description;
        std::vector<PhotoSize::Ptr> photo;
        std::string text;
        std::vector<MessageEntity::Ptr> text_entities;
        Animation::Ptr animation;
    };

    inline void from_json(const ExtendedCpp::Json& json, Game& object) noexcept
    {
        VALUE_FROM_JSON(title)
        VALUE_FROM_JSON(description)
        OBJECTS_FROM_JSON(photo)
        VALUE_FROM_JSON(text)
        OBJECTS_FROM_JSON(text_entities)
        OBJECT_FROM_JSON(animation)
    }
}

#endif