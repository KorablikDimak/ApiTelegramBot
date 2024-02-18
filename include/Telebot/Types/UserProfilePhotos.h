#ifndef Telebot_UserProfilePhotos_H
#define Telebot_UserProfilePhotos_H

#include <vector>

#include <Telebot/Types/PhotoSize.h>

namespace Telebot
{
    class UserProfilePhotos
    {
    public:
        typedef std::shared_ptr<UserProfilePhotos> Ptr;

        std::int32_t TotalCount;
        std::vector<std::vector<PhotoSize::Ptr>> Photos;
    };
}

#endif