#include <Bot.h>
#include <memory>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Invalid token\n";
        return EXIT_FAILURE;
    }
    std::shared_ptr<TG::MovieBot> movieBot = std::make_shared<TG::MovieBot>(argv[1]);
    // movieBot->run();
    return 0;
}
