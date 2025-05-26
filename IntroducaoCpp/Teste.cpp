#include <iostream>
#include <fstream>

namespace SepararLogica
{
    /*
    Separar l�gica de neg�cio de depend�ncias externas
    Evite misturar l�gica com chamadas a banco de dados, arquivos ou interfaces gr�ficas.
    */

    namespace Dificil
    {
        void saveUser(const std::string& name) {
            std::ofstream file("users.txt");
            file << name;
        }
    }

    namespace Facil
    {
        class IUserRepository {
        public:
            virtual void save(const std::string& name) = 0;
            virtual ~IUserRepository() = default;
        };

        class FileUserRepository : public IUserRepository {
        public:
            void save(const std::string& name) override {
                std::ofstream file("users.txt");
                file << name;
            }
        };

        // Consigo fazer inje��o de deped�ncia
        void saveUser(IUserRepository& repo, const std::string& name) {
            repo.save(name);
        }
    }
}

namespace InjecaoDependencia
{
    /*
    Evite criar objetos dentro da classe, injete-os.
    */
    namespace Dificil
    {
        class Database
        {
        public:
            void query(std::string s) {};
        };

        class Service {
            Database db;
        public:
            void doSomething() { db.query("SELECT *"); }
        };
    }

    namespace Facil
    {
        class IDatabase
        {
        public:
            void query(std::string s) = 0;
        };

        class Service {
            IDatabase& db;
        public:
            Service(IDatabase& db) : db(db) {}
            void doSomething() { db.query("SELECT *"); }
        };
    }
}

namespace EvitarStatic
{
    namespace Dificiil
    {
        class Logger
        {
        public:
            static Logger GetInstance()
            {
                static Logger logger;
                return logger;
            }
            
            void Log(std::string s) {}
        };

        int main()
        {
            Logger::GetInstance().Log("error");

            return 0;
        }
    }

    namespace Facil
    {
        class Logger {
        public:
            virtual void log(const std::string& message) = 0;
            virtual ~Logger() = default;
        };

        class ConsoleLogger : public Logger {
            void log(const std::string& message) override {
                std::cout << message;
            }
        };

        //Inje��o de depend�ncia
        void process(Logger& logger) {
            logger.log("error");
        }
    }
}
