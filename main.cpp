#include "PeriodicTaskScheduler.h"
#include <boost/thread.hpp>

void fun()
{
 ;
}
int main()
{

        PeriodicScheduler scheduler;

        // Schedule tasks initially
        //scheduler.schedule_periodic(scheduler.getUid(), fun, std::chrono::system_clock::now(), 5);
        scheduler.PeriodicTask(scheduler.getUid(), fun, std::chrono::system_clock::now(), 5);

        // Run the scheduler in a new thread
        boost::thread th(&PeriodicScheduler::run, &scheduler);

        std::uint32_t taskid;
        int interval = 5;

        int option;

        //do-while loop to display menu until user select to exit program
        do
        {
                //Displaying Options for the menu
                std::cout << std::endl;
                std::cout << "1) Display Task List " << std::endl;                                      // Option to view task list
                std::cout << "2) Add new Task " << std::endl;                                           // Option to add new task
                std::cout << "3) Update Task Interval " << std::endl;                                   // Option to update an existing task
                std::cout << "4) Delete Task" << std::endl;                                             // Option to delete task
                std::cout << "5) Exit Program " << std::endl;                                           // Option to exit the program

                std::cout << "Please select an option : \n";
                std::cin >> option;

                switch (option)
                {
                case 1:
                        scheduler.get_tasks_overview();
                        break;

                case 2:
                        int task_option;
                        std::cout << "Enter Task interval ";                                            // Get new task interval
                        std::cin >> interval;
                        if (interval)
                        {
                                try {
                                        scheduler.PeriodicTask(scheduler.getUid(),                      // Schedule task type 1
                                                fun,
                                                std::chrono::system_clock::now(), interval);
                                }
                                catch (std::exception const &e) {
                                        std::cout << e.what() << std::endl;
                                }
                        }
                        else
                        {
                                std::cout << "Wrong Input!";
                        }
                        break;

                case 3:
                        scheduler.get_tasks_overview();                                                 // Displays task list before prompting for task id
                        std::cout << "Enter Task UID and new Interval separated by spaces to update ";
                        std::cin >> taskid >> interval;                                                 // Prompt user for new task interval
                        scheduler.update_task(taskid, interval);                                        // Add task to update set
                        break;

                case 4:
                        std::uint32_t taskid;
                        scheduler.get_tasks_overview();                                                 // Displays task list before prompting for task id
                        std::cout << "Enter Task UID to delete ";
                        std::cin >> taskid;                                                             // Prompt user for task ID
                        scheduler.delete_task(taskid);                                                  // Add task to delete set
                        break;

                case 5:
                        scheduler.stop();                                                               // Stop the scheduler
                        break;

                default:
                        std::cout << "Incorrect option entered!" << std::endl;
                }
        } while (option != 5);

        th.join();
        return 0;
}
