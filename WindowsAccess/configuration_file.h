#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

#include <string>

extern std::string config_name;
extern float timer_sleep;
extern bool logs_status;

bool check_apps_folder_status(std::string location);
bool read_configuration_file(std::string location);
void send_report_logs(std::string location, std::string user);

#endif