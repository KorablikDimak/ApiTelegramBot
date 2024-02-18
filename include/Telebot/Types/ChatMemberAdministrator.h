#ifndef Telebot_ChatMemberAdministrator_H
#define Telebot_ChatMemberAdministrator_H

#include <Telebot/Types/ChatMember.h>

namespace Telebot
{
    class ChatMemberAdministrator final : public ChatMember
    {
    public:
        typedef std::shared_ptr<ChatMemberAdministrator> Ptr;

        static const std::string STATUS;

        ChatMemberAdministrator()
        {
            status = STATUS;
        }

        bool CanBeEdited;
        bool IsAnonymous;
        bool CanManageChat;
        bool CanDeleteMessages;
        bool CanManageVideoChats;
        bool CanRestrictMembers;
        bool CanPromoteMembers;
        bool CanChangeInfo;
        bool CanInviteUsers;
        bool CanPostMessages;
        bool CanEditMessages;
        bool CanPinMessages;
        bool CanManageTopics;
        std::string CustomTitle;
    };
}

#endif