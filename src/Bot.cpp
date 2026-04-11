#include <Bot.h>
#include <exception>

TG::MovieBot::MovieBot(const char *t) : m_token{t}
{
    std::cout << "TOKEN = " << m_token << std::endl;
}

void TG::MovieBot::run()
{
    std::cout << "STARTED!\n";
    while (true)
    {
        try
        {
            // Формируем запрос на получение обновлений
            json payload =
            {
                {"offset", m_last_update_id + 1},
                {"timeout", 30},  // Long polling на 30 секунд
                {"allowed_updates", json::array({"message"})}
            };
            auto response = SendRequest("getUpdates", payload);

            if (response.contains("ok") && response["ok"])
                ProcessUpdate(response);
            else
                std::cerr << "API error: " << response.dump() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Run loop error: " << e.what() << std::endl;
        }
    }
}

json TG::MovieBot::SendRequest(const std::string &method, const json &payload)
{

}

void TG::MovieBot::SendMessage(int64_t chat_id, const std::string &text)
{

}

void TG::MovieBot::ProcessUpdate(const json &updates)
{

}
