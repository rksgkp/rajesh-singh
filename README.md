
Implements a generic, periodic task scheduler in C++ (. Each task runs on a separate, configurable interval (e.g., every 30 seconds). It can execute any type of task, where a task is just an abstraction for a block of code that when run, produces some output. Includes functions to accept new tasks, cancel tasks, and change the schedule of tasks.

The output of each task will be one or more "metrics" in the form of decimal values
