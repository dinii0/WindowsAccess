#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>

#include "configuration_file.h"

namespace fs = std::filesystem;

std::string config_name = "unlock";
float timer_sleep = 10.0;
bool logs_status = true;

std::string get_current_time(std::string format) {
	auto now = std::chrono::system_clock::now();
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

	std::tm now_tm;
	localtime_s(&now_tm, &now_time_t);

	std::ostringstream oss;
	oss << std::put_time(&now_tm, format.c_str());

	return oss.str();
}

bool check_apps_folder_status(std::string location) {
	bool status = true;
	location += "\\WindowsAccess";
	if (!fs::exists(location)) {
		fs::create_directory(location);
		status = false;
	}

	std::ifstream file(location + "\\configs.ini");
	if (!file.is_open()) {
		std::ofstream config_file(location + "\\configs.ini");
		config_file << "[Settings]\n";
		config_file << "Folder=" << config_name << "\n";
		config_file << "Timer=" << std::to_string(timer_sleep) << "\n";
		config_file << "Logs=" << ((logs_status) ? "1" : "0") << "\n";
		config_file.close();
		status = false;
	}

	location += "\\Logs";
	if (!fs::exists(location)) {
		fs::create_directory(location);
		status = false;
	}

	return status;
}

bool read_configuration_file(std::string location) {
	location += "\\WindowsAccess\\configs.ini";
	std::ifstream config(location);

	if (!config) {
		return false;
	}

	std::string line, key, value;
	size_t pos;

	while (std::getline(config, line)) {

		if (line.empty() || line[0] == ';' || line[0] == '#' || line[0] == '[') {
			continue;
		}

		pos = line.find('=');
		if (pos != std::string::npos) {
			key = line.substr(0, pos);
			value = line.substr(pos + 1);

			key.erase(0, key.find_first_not_of(" \t"));
			key.erase(key.find_last_not_of(" \t") + 1);
			value.erase(0, value.find_first_not_of(" \t"));
			value.erase(value.find_last_not_of(" \t") + 1);

			if (key == "Folder") {
				config_name = value;
			}
			else if (key == "Timer") {
				timer_sleep = std::stof(value);
			}
			else if (key == "Logs") {
				logs_status = (value[0] == '1') ? true : false;
			}
		}
		else continue;
	}

	config.close();
	return true;
}

void send_report_logs(std::string location, std::string user) {
	if (!logs_status)
		return;

	location += "\\WindowsAccess\\Logs\\Attempt_" + get_current_time("%Y-%m-%d") + ".log";
	std::ofstream logs_file(location, std::ios::app);
	logs_file << "[" << get_current_time("%A, %B %d, %Y %I:%M:%S %p") << "] There was an attempt logging in through user: " << user << "\n";
	logs_file.close();
}