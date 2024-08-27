#ifndef Telebot_Telebot_H
#define Telebot_Telebot_H

#include <future>

#include <Events/Event.h>
#include <Common/CancellationTokenSource.h>

#include <Telebot/TelebotApi.h>

namespace Telebot
{
    typedef std::shared_ptr<Events::Event<const Message::Ptr&>> MessageEvent;
    typedef std::function<void(const Message::Ptr&)> MessageHandler;

    typedef std::shared_ptr<Events::Event<const CallbackQuery::Ptr&>> CallbackQueryEvent;
    typedef std::function<void(const CallbackQuery::Ptr&)> CallbackHandler;

    class Telebot
    {
    private:
        std::unique_ptr<TelebotApi> _api;
        std::unique_ptr<Common::CancellationTokenSource> _acceptorTokenSource;
        std::future<void> _acceptor;

        static const std::int32_t LIMIT;
        std::int32_t _timeout;

        void Accept() noexcept;

    public:
        explicit Telebot(const std::string& token) noexcept;
        ~Telebot();

        void Start() noexcept;
        void StartAsync() noexcept;
        void Stop() const noexcept;

        void SetTimeout(std::int32_t timeout) noexcept;

        [[nodiscard]]
        std::future<Message::Ptr> SendMessageAsync(const std::int64_t& chatId, const std::string& text,
                                                   const GenericReply::Ptr& genericReply = nullptr) const noexcept;
        [[nodiscard]]
        std::future<bool> SetCommandAsync(const std::string& command, const std::string& description) const noexcept;
        [[nodiscard]]
        std::future<bool> SetCommandAsync(const BotCommand::Ptr& command) const noexcept;
        [[nodiscard]]
        std::future<bool> SetCommandsAsync(const std::vector<std::pair<std::string, std::string>>& commands) const noexcept;
        [[nodiscard]]
        std::future<bool> SetCommandsAsync(const std::vector<BotCommand::Ptr>& commands) const noexcept;
        [[nodiscard]]
        std::future<std::string> DownloadFileAsync(const std::string& fileId, const std::string& toDirectory) const noexcept;
        [[nodiscard]]
        std::future<Message::Ptr> SendPhotoAsync(const std::int64_t& chatId,
                                                 const std::variant<std::string, InputFile::Ptr>& url) const noexcept;
        [[nodiscard]]
        std::future<bool> AnswerCallbackQueryAsync(const std::string& callbackQueryId, const std::string& text = "",
                                                   const bool& showAlert = false) const noexcept;
        [[nodiscard]]
        std::future<Message::Ptr> EditMessageTextAsync(const std::int64_t& chatId, const std::int32_t& messageId,
                                                       const std::string& text, const GenericReply::Ptr& genericReply = nullptr) const noexcept;
        [[nodiscard]]
        std::future<Message::Ptr> SendVoiceAsync(const std::int64_t& chatId,
                                                 const std::variant<std::string, InputFile::Ptr>& filePath) const noexcept;

    private:
        MessageEvent _onAnyMessage;
        std::map<std::string, MessageEvent> _onMessage;
        std::map<std::string, MessageEvent> _onCommand;
        MessageEvent _onVoice;
        CallbackQueryEvent _onAnyCallbackQuery;
        std::map<std::string, CallbackQueryEvent> _onCallbackQuery;

    public:
        MessageEvent& OnAnyMessage() noexcept;
        void OnAnyMessage(MessageHandler&& handler) const noexcept;
        MessageEvent& OnMessage(const std::string& message) noexcept;
        void OnMessage(const std::string& message, MessageHandler&& handler) noexcept;
        MessageEvent& OnCommand(const std::string& command) noexcept;
        void OnCommand(const std::string& command, MessageHandler&& handler) noexcept;
        MessageEvent& OnVoice() noexcept;
        void OnVoice(MessageHandler&& handler) const noexcept;
        CallbackQueryEvent& OnAnyCallbackQuery() noexcept;
        void OnAnyCallbackQuery(CallbackHandler&& handler) const noexcept;
        CallbackQueryEvent& OnCallbackQuery(const std::string& callback_data) noexcept;
        void OnCallbackQuery(const std::string& callback_data, CallbackHandler&& handler) noexcept;
    };
}

#endif