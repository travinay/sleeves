#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <string>
 
std::condition_variable g_Bell; //вводим условные переменные, для которых будем менять статусы - Звонок
std::condition_variable_any g_Door; //Дверь
 
class Manager //создаем класс тупого манагера
{
public:
    void ComeToWork() //он приходит на работу - это одна из его функций. Так как методы публичные - тупого манагера может вызвать на работу любой чел. Манагеру сложно справляться с понятием "тайм менеджмент"
    {
        std::cout << "Hey security, please open the door!\n"; //так как мэнеджер дико важный, он просит охрану отрыть дверь
        g_Bell.notify_one(); //функция осуществляющая звонок охране
        std::mutex mutex;
        mutex.lock();
        g_Door.wait(mutex);//мьютакс прерывает действие звонка
        mutex.unlock();//перевел дверь из статуса закрыт в статус открыт
    }
};
 
class Security //создаем класс охраны Мишустина
{
    static bool m_SectorClear; //объявляем методы класса - упитый охраник чекает каждую секунду или чаще - чист ли горизонт
    static std::mutex m_SectorMutex;
public:
    static bool SectorClear()
    {
        std::lock_guard<std::mutex> lock(m_SectorMutex);
        return m_SectorClear;
    }
    void NotifyFellows()
    {
        std::lock_guard<std::mutex> lock(m_SectorMutex);
        m_SectorClear = false;//то есть как только наш амбал узрел, что никого нет - мюьтакс прерывает поток поиска людей и переводит охрану в режим действия
    }
    void WorkHard() //Охранику придется жестко поработать
    {
        m_SectorClear = true;//индикатор, обнаружен ли коллега
        std::mutex mutex;
        std::unique_lock<std::mutex> lock(mutex);
        while(true)
        {
            if(g_Bell.wait_for(lock, std::chrono::seconds(5)) == std::cv_status::timeout)// охранник послушал звонок 5 секунд - там играла его любимая Тэйлор свифт, он тут же откладывает свой тик-ток, прощается за руку с каждым из коллег, грозно смотрит на потенциальных студентов-террористов
                std::this_thread::sleep_for(std::chrono::seconds(10));// и через 10 секунд все таки решит посуетиться, как открыть двери 
            else
            {
                NotifyFellows(); //пока буловая переменная обнаружения коллег все еще true, юзается функция, прерывающая поиск людей в зоне обозримости
                g_Door.notify_one();//открывается дверь (условная переменная "дверь" приобретает статус открыта)
                std::cout << "Hello Great Manager, your slaves are ready to serve you!\n" << std::endl;//Наш потрясающий NPC решает проявить свои гачи навывки
            }
        }
    }
};
 
bool Security::m_SectorClear;
std::mutex Security::m_SectorMutex;
 
class Programmer//еще у нас есть работник программист, который непонятно чем заниматся по жизни
{
public:
    void WorkHard()//у него где-то в глубине души есть функция жестко поработать для начальства
    {
        std::cout << "Let's write some govnokod!\n" << std::endl;//это всего лишь самообман...
        int i = 0;//как нифига не было сделано, так и не будет (спойлер!)
        while(true)
        {
            i++;// .----вот мы пописали код, он работает<-------------------------.
            i--;// *--->получили по шапке от тестировщиков и все переделываем ____|
        }
    }
    void PlayStarcraft()
    {
        while(Security::SectorClear())//пока горизонт чист и нет начальства пинаем игры
            ;//Играем! :)
        WorkHard();// Работаем :(
    }
};
 
 
 
int main()
{
    Manager manager; //Имеет одного безымянного програмиста
    Programmer programmer;//бездельника прогера
    Security security;//охранника с элементами садо-маза
 
    auto managerCall = [&manager]()
    {
        manager.ComeToWork();//вызываем методы, что делают чуваки в течении рабочего дня
    };
    auto programmerCall = [&programmer]()
    {
        programmer.PlayStarcraft();
    };
    auto securityCall = [&security]()
    {
        security.WorkHard();
    };
    std::thread securityThread(securityCall);//мультипоточное программирование позволяет этим людям одновременно бездарно существовать
    std::thread programmerThread(programmerCall);//(...)
    std::this_thread::sleep_for(std::chrono::minutes(1));//сия вставка нужна чтобы показать в течении секунды, как будут вести себя работнички до прихода манагера
    std::thread managerThread(managerCall);//манагер пришел
    
    managerThread.join();//Ждем завершение выполнения вышеуказанных действий, не подсовывая следующую: наши герои далеко не мультизадачны сами по себе, в отличии от кода 
    programmerThread.join();
    securityThread.join();
 
    return 0;
}